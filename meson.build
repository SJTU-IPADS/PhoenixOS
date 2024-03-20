# >>> project definition
project('PhoenixOS', ['CPP'],
	# Get version number from file.
	version: run_command(find_program('cat'),files('./VERSION'), check: true).stdout().strip(),
)
project_name = 'phoenix_os'
project_name_abbreviation = 'pos'


# >>>>>>>>>>>>>> build prepare >>>>>>>>>>>>>>
# get environment variables of the build process
env = environment()

# we use pkg-config to collect dependecies
pkgconfig = find_program('pkg-config')

# compile flags
c_args = []

# load flags
ld_args = []

# dependencies
deps = []

# include directories
inc_dirs = []

# all libraries that want to be statically linked
libraries = []

# source files
sources = []

# current directory of this meson file
meson_file_dir = meson.source_root()


# >>>>>>>>>>>>>> setup configurations (please modified here) >>>>>>>>>>>>>>
# config:   target selection (options: cuda, todos: rocm/ascend)
target = 'cuda'

# config:   checkpoint optimization level (p.s., 0 is no checkpoint)
ckpt_opt_level = 2

# config:   sync/async checkpoint (level 1,2) optimization -> flag to control increamental checkpoint
enable_ckpt_increamental = 1

# config:   async checkpoint (level 2) optimization -> flag to control checkpoint pipeline
enable_ckpt_pipeline = 1

# config:   async checkpoint (level 2) optimization -> flag to control checkpoint orchestration
enable_ckpt_orchestration = 0

# config:   TSC register frequency
tsc_reg_freq = 2200000000

# config:   checkpoint interval (unit in ms)
ckpt_interval_ms = 500

# config:   log file output path
log_file_path = '/root/dag.pos'

# switch:   whether to check correctness of function parameters, return values, etc.,
#           which might cause extra runtime burden, should only be enabled while debuging
enable_runtime_debug_check = 0

# switch:   whether to check whether POS finish the hijacking logic of called APIs,
#           which might cause extra runtime burden, should only be enabled while debuging
enable_hijack_api_check = 0

# switch:   whether to print all fatal messages
enable_print_error = 1

# switch:   whether to print all warning messages
enable_print_warn = 1

# switch:   whether to print all log messages
enable_print_log = 1

# switch:   whether to print all debug messages
enable_print_debug = 0

# switch:   whether to print fatal/warn/debug/log with colors
#           should be disabled when try to dump all outputs to a file
enable_print_with_color = 1

# we need to hardcoded some configurations as source code
subdir('pos/include')

# print configurations
message('>>> Build configurations:')
message('>>>>>> [Config] target:                                ' + target)
message('>>>>>> [Config] TSC register frequency:                ' + tsc_reg_freq.to_string())
message('>>>>>> [Config] checkpoint optimization level:         ' + ckpt_opt_level.to_string())
if ckpt_opt_level >= 1
    message('       >>>>>> [Config] enable_ckpt_increamental:       ' + enable_ckpt_increamental.to_string())
else
    message('       >>>>>> [Config] enable_ckpt_increamental:       N/A')
endif
if ckpt_opt_level >= 2
    message('       >>>>>> [Config] enable_ckpt_pipeline:           ' + enable_ckpt_pipeline.to_string())
    message('       >>>>>> [Config] enable_ckpt_orchestration:      ' + enable_ckpt_orchestration.to_string())
else
    message('       >>>>>> [Config] enable_ckpt_pipeline:           N/A')
    message('       >>>>>> [Config] enable_ckpt_orchestration:      N/A')
endif
message('>>>>>> [Config] checkpoint interval (ms):              ' + ckpt_interval_ms.to_string())
message('>>>>>> [Config] log file output path:                  ' + log_file_path)
message('>>>>>> [Switch] enable_runtime_debug_check:            ' + enable_runtime_debug_check.to_string())
message('>>>>>> [Switch] enable_hijack_api_check:               ' + enable_hijack_api_check.to_string())
message('>>>>>> [Switch] enable_print_error:                    ' + enable_print_error.to_string())
message('>>>>>> [Switch] enable_print_warn:                     ' + enable_print_warn.to_string())
message('>>>>>> [Switch] enable_print_log:                      ' + enable_print_log.to_string())
message('>>>>>> [Switch] enable_print_debug:                    ' + enable_print_debug.to_string())
message('>>> Build configurations done\n')

# >>>>>>>>>>>>>> find target libraries >>>>>>>>>>>>>>
if target == 'cuda'
    cuda_version = '11.3'
    cuda_pc_path = '/usr/lib/pkgconfig'
    cuda_modules = ['cublas', 'cuda', 'cudart', 'cufft', 'cufftw', 'cuinj64', 'curand', 'cusolver', 'cusparse']
    founded_cuda_modules = []
    message('>>> Detecting CUDA toolkit, assume:')
    message('>>>>>> CUDA version:               ' + cuda_version)
    message('>>>>>> Path of pkg-config files:   ' + cuda_pc_path)

    env.set('PKG_CONFIG_PATH', cuda_pc_path)
    foreach cuda_module : cuda_modules
        cuda_module_cflags = run_command(pkgconfig, '--cflags', cuda_module+'-'+cuda_version, env: env, check: false)
        cuda_module_ldflags = run_command(pkgconfig, '--libs', '--static', cuda_module+'-'+cuda_version, env: env, check: false) # add '--static' option if static link is needed
        cuda_module_version = run_command(pkgconfig, '--modversion', cuda_module+'-'+cuda_version, env: env, check: false)
        if cuda_module_cflags.returncode() != 0 or cuda_module_ldflags.returncode() != 0 or cuda_module_version.returncode() != 0
            message('>>>>>> Failed to find ' + cuda_module+'-'+cuda_version)
        else
            founded_cuda_modules += cuda_module
            c_args += cuda_module_cflags.stdout().split()
            ld_args += cuda_module_ldflags.stdout().split()
            message('>>>>>> Found ' + cuda_module + ', version is ' + cuda_module_version.stdout().split()[0])
        endif
    endforeach
    assert(
        founded_cuda_modules.length() == cuda_modules.length(),
        'Only find ' + founded_cuda_modules.length().to_string() + ' CUDA modules, expected ' + cuda_modules.length().to_string()
    )
else
    assert(false, 'target ' + target + ' is currently not supported')
endif
message('>>> Detecting CUDA toolkit done\n')


# >>>>>>>>>>>>>> setup sources and includes >>>>>>>>>>>>>>
sources += ['pos/src/handle.cpp', 'pos/src/oob.cpp', 'pos/src/api_context.cpp', 'pos/src/client.cpp']

if ckpt_opt_level == 0
    sources += ['pos/src/checkpoint_o0.cpp']
elif ckpt_opt_level == 1 or ckpt_opt_level == 2
    sources += ['pos/src/checkpoint_o1_o2.cpp']
endif

if target == 'cuda'
    sources += [
        'pos/cuda_impl/api_context.cpp',
        'pos/cuda_impl/utils/fatbin.cpp',
        'pos/cuda_impl/parser/cublas.cpp',
        'pos/cuda_impl/parser/cuda_driver.cpp',
        'pos/cuda_impl/parser/cuda_runtime.cpp',
        'pos/cuda_impl/worker/cublas.cpp',
        'pos/cuda_impl/worker/cuda_driver.cpp',
        'pos/cuda_impl/worker/cuda_runtime.cpp'
    ]
else
    assert(false, 'target ' + target + ' is currently not supported')
endif

inc_dirs += ['./']

# >>>>>>>>>>>>>> setup third party dependencies >>>>>>>>>>>>>>

message('>>> Setup libclang')
libclang_ld_args = ['-L' + meson_file_dir + '/third_party/libclang-static-build/lib', '-lclang']
libclang_inc_dirs = ['./third_party/libclang-static-build/include']
message('>>>>>> Link option:')
message(libclang_ld_args)
message('>>>>>> Include path:')
message(libclang_inc_dirs)
ld_args += libclang_ld_args
inc_dirs += libclang_inc_dirs
message('>>> Setup libclang done\n')

# message('>>> Setup hiredis')
# hiredis_ld_args = ['-lhiredis']
# hiredis_inc_dirs = ['./third_party/hiredis']
# message('>>>>>> Link option:')
# message(hiredis_ld_args)
# message('>>>>>> Include path:')
# message(hiredis_inc_dirs)
# ld_args += hiredis_ld_args
# inc_dirs += hiredis_inc_dirs
# message('>>> Setup hiredis done\n')

message('>>> Setup libevent')
libevent_ld_args = ['-levent']
libevent_inc_dirs = ['./third_party/libevent/include']
message('>>>>>> Link option:')
message(libevent_ld_args)
message('>>>>>> Include path:')
message(libevent_inc_dirs)
ld_args += libevent_ld_args
inc_dirs += libevent_inc_dirs
message('>>> Setup libevent done\n')

message('>>> Setup librt') # for support shm_x
ld_args += ['-lrt']
message('>>> Setup librt done\n')

message('>>> Setup pthread') # for support pthread_x
ld_args += ['-pthread']
message('>>> Setup pthread done\n')

message('>>> Setup libelf') # for support elf_x
ld_args += ['-lelf']
message('>>> Setup libelf done\n')

# message('>>> Setup boost')
# boost_dep = dependency('boost')
# deps += boost_dep
# message('>>> Setup boost done\n')




# >>>>>>>>>>>>>> setup build options >>>>>>>>>>>>>>
c_args += ['--std=c++17']


# >>>>>>>>>>>>>> start building >>>>>>>>>>>>>>
library(project_name_abbreviation, sources,
	dependencies : deps,
	cpp_args: c_args,
	link_args: ld_args,
	include_directories: inc_dirs,
	install: false
)
