#include <iostream>
#include <chrono>
#include <cassert>
#include <stdio.h>
#include <stdlib.h>
#include <nccl.h>
#include <cuda_runtime.h>
#include <mpi.h>

#define N 2  // 每个进程的数据大小

#define CHECK_NCCL(nccl_call)                                                   \
    if ((ncclResult = (nccl_call)) != ncclSuccess) {                            \
        fprintf(stderr, "NCCL error: %s\n", ncclGetErrorString(ncclResult));    \
        exit(EXIT_FAILURE);                                                     \
    }

/*!
 *  \brief  HPET-based timer
 *  \note   we provide HPET-based timer mainly for measuring the frequency of TSC
 *          more accurately, note that HPET is expensive to call
 */
class POSUtilHpetTimer {
 public:
    POSUtilHpetTimer(){}
    ~POSUtilHpetTimer() = default;

    /*!
     *  \brief  start timing
     */
    inline void start(){
        this->_start_time = std::chrono::high_resolution_clock::now();
    }

    /*!
     *  \brief  stop timing and obtain duration (ns)
     *  \return duration (ns)
     */
    inline double stop_get_ns() const {
        return static_cast<double>(
            std::chrono::duration_cast<std::chrono::nanoseconds>(
                std::chrono::high_resolution_clock::now() - this->_start_time
            ).count()
        );
    }

    /*!
     *  \brief  stop timing and obtain duration (us)
     *  \return duration (us)
     */
    inline double stop_get_us() const {
        return stop_get_ns() / 1e3;
    }

    /*!
     *  \brief  stop timing and obtain duration (ms)
     *  \return duration (ms)
     */
    inline double stop_get_ms() const {
        return stop_get_ns() / 1e6;
    }

    /*!
     *  \brief  stop timing and obtain duration (s)
     *  \return duration (s)
     */
    inline double stop_get_s() const {
        return stop_get_ns() / 1e9;
    }

 private:
    // start time of the timing
    std::chrono::time_point<std::chrono::high_resolution_clock> _start_time;
};


/*!
 *  \brief  TSC-based timer
 */
class POSUtilTscTimer {
 public:
    POSUtilTscTimer(){ 
        this->update_tsc_freq(); 
    }
    ~POSUtilTscTimer() = default;

    /*!
     *  \brief  ontain TSC tick
     *  \return TSC tick
     */
    static inline uint64_t get_tsc(){
        uint64_t a, d;
        __asm__ volatile("rdtsc" : "=a"(a), "=d"(d));
        return (d << 32) | a;
    }

    /*!
     *  \brief  update the TSC frequency
     */
    inline void update_tsc_freq(){
        POSUtilHpetTimer hpet;
        uint64_t sum = 5;

        hpet.start();

        // Do not change this loop! The hardcoded value below depends on this loop
        // and prevents it from being optimized out.
        const uint64_t rdtsc_start = this->get_tsc();
        for (uint64_t i = 0; i < 1000000; i++) {
            sum += i + (sum + i) * (i % sum);
        }
        assert(sum == 13580802877818827968ull);
        const uint64_t rdtsc_cycles = this->get_tsc() - rdtsc_start;

        this->_tsc_freq_g = rdtsc_cycles * 1.0 / hpet.stop_get_ns();
        this->_tsc_freq = this->_tsc_freq_g * 1000000000;
    }

    /*!
     *  \brief  calculate from tick range to duration (ms)
     *  \param  e_tick  end tick
     *  \param  s_tick  start tick
     *  \return duration (ms)
     */
    inline double tick_range_to_ms(uint64_t e_tick, uint64_t s_tick){
        return (double)(e_tick - s_tick) / (double) this->_tsc_freq * (double)1000.0f;
    }

    /*!
     *  \brief  calculate from tick range to duration (us)
     *  \param  e_tick  end tick
     *  \param  s_tick  start tick
     *  \return duration (us)
     */
    inline double tick_range_to_us(uint64_t e_tick, uint64_t s_tick){
        return (double)(e_tick - s_tick) / (double) this->_tsc_freq * (double)1000000.0f;
    }

    /*!
     *  \brief  calculate from duration (ms) to tick steps
     *  \param  duration  duration (ms)
     *  \return tick steps
     */
    inline double ms_to_tick(uint64_t duration){
        return (double)(duration) / (double)1000.0f * (double) this->_tsc_freq;
    }

    /*!
     *  \brief  calculate from duration (us) to tick steps
     *  \param  duration  duration (us)
     *  \return tick steps
     */
    inline double us_to_tick(uint64_t duration){
        return (double)(duration) / (double)1000000.0f * (double) this->_tsc_freq;
    }

    /*!
     *  \brief  calculate from tick steps to duration (ms)
     *  \param  tick steps 
     *  \return duration  duration (ms)
     */
    inline double tick_to_ms(uint64_t ticks){
        return (double)(ticks) * (double)1000.0f / (double) this->_tsc_freq;
    }

    /*!
     *  \brief  calculate from tick steps to duration (us)
     *  \param  tick steps 
     *  \return duration  duration (us)
     */
    inline double tick_to_us(uint64_t ticks){
        return (double)(ticks) * (double)1000000.0f / (double) this->_tsc_freq;
    }

 private:
    // frequency of TSC register
    double _tsc_freq_g;
    double _tsc_freq;
};


int main(int argc, char* argv[]) {
    int rank, size;
    float *sendbuff, *recvbuff;
    ncclComm_t comm, newcomm;
    ncclResult_t ncclResult;
    cudaStream_t stream;
    ncclUniqueId uniqueId;

    POSUtilTscTimer tsc_timer;
    uint64_t s_tick, e_tick;

    // 初始化 MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // 在 rank 0 进程上生成 ncclUniqueId
    if (rank == 0) {
        ncclGetUniqueId(&uniqueId);
    }

    // 广播 ncclUniqueId 给所有进程
    MPI_Bcast(&uniqueId, sizeof(ncclUniqueId), MPI_BYTE, 0, MPI_COMM_WORLD);

    // 初始化 CUDA
    cudaSetDevice(rank);
    cudaMalloc((void**)(&sendbuff), N*sizeof(float));
    cudaMalloc((void**)(&recvbuff), N*sizeof(float));

    // 填充随机数据
    float host_sendbuff[N];
    for (int i = 0; i < N; i++) {
        host_sendbuff[i] = (float)rank + 1;  // 每个进程填充不同的值
    }
    printf("Rank %d send: [%f, %f]\n", rank, host_sendbuff[0], host_sendbuff[1]);
    cudaMemcpy(sendbuff, host_sendbuff, N * sizeof(float), cudaMemcpyHostToDevice);

    // 创建全连接 NCCL communicator
    s_tick = POSUtilTscTimer::get_tsc();
    CHECK_NCCL(ncclCommInitRank(&comm, size, uniqueId, rank));
    e_tick = POSUtilTscTimer::get_tsc();
    printf("Rank %d all-connected init duration: %lf ms\n", rank, tsc_timer.tick_to_ms(e_tick-s_tick));

    // 创建残存连接
    s_tick = POSUtilTscTimer::get_tsc();
    ncclCommSplit(comm, rank<4 ? 0 : NCCL_SPLIT_NOCOLOR, rank, &newcomm, NULL);
    e_tick = POSUtilTscTimer::get_tsc();
    printf("Rank %d sub-connected init duration: %lf ms\n", rank, tsc_timer.tick_to_ms(e_tick-s_tick));

    // 创建 CUDA stream
    cudaStreamCreate(&stream);

    // 执行 AllReduce 操作
    CHECK_NCCL(ncclAllReduce(sendbuff, recvbuff, N, ncclFloat, ncclSum, comm, stream));
    
    // Synchronize the stream
    cudaStreamSynchronize(stream);

    // 打印结果
    float host_recvbuff[N];
    cudaMemcpy(host_recvbuff, recvbuff, N * sizeof(float), cudaMemcpyDeviceToHost);
    printf("Rank %d received: [%f, %f]\n", rank, host_recvbuff[0], host_recvbuff[1]);

    // 释放资源
    cudaFree(sendbuff);
    cudaFree(recvbuff);
    ncclCommDestroy(comm);
    cudaStreamDestroy(stream);
    MPI_Finalize();

    return 0;
}
