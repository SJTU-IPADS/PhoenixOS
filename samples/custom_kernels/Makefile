NVCC ?= nvcc

all: main

main: main.cu
	$(NVCC) $^ -o $@ -lcuda -std=c++11

clean:
	rm main
