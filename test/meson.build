# >>> project definition
project('PhoenixOS_Test', ['CPP'],
	# Get version number from file.
	version: run_command(find_program('cat'),files('../VERSION'), check: true).stdout().strip(),
)
project_name = 'phoenix_os_test'
project_name_abbreviation = 'pos_test'

add_project_arguments('-O0',  language : 'cpp')

scan_src_path = meson.current_source_dir() + '../scripts/utils/glob_src.py'

# >>>>>>>>>>>>>> build prepare >>>>>>>>>>>>>>
# get environment variables of the build process
env = environment()

# we use pkg-config to collect dependecies
pkgconfig = find_program('pkg-config')
bash = find_program('bash')

# path of built libraries by PhOS build system
lib_path = meson.current_source_dir() + '/../lib'
googletest_abs_path = meson.current_source_dir() + '/../third_party/googletest'
googletest_rlt_path = '../../third_party/googletest'    # from the build directory

# compile flags
c_args = []

# load flags
ld_args = [ '-L'+lib_path ]

# include directories
inc_dirs = [ '../lib', '../lib/pos/include', '../' ]

# source files
sources = []


# >>>>>>>>>>>>>> setup configurations >>>>>>>>>>>>>>
# build config: root directory of the project
project_root_dir = run_command('sh', '-c', 'echo $POS_BUILD_ROOT').stdout().strip()
if project_root_dir != ''
    assert(false, 'no project root directory was set')
endif

# config:   target selection (options: cuda, todos: rocm/ascend)
target = run_command('sh', '-c', 'echo $POS_BUILD_TARGET').stdout().strip()
if target == ''
    target = 'cuda'
endif
if target != 'cuda'
    assert(false, 'target ' + target + ' is currently not supported')
endif

# config:   target version (example: "11.3" for CUDA 11.3)
target_version = run_command('sh', '-c', 'echo $POS_BUILD_TARGET_VERSION').stdout().strip()
if target_version == ''
    assert(false, 'no target version was provided')
endif

# switch:   whether to check correctness of function parameters, return values, etc.,
#           which might cause extra runtime burden, should only be enabled while debuging
enable_runtime_debug_check = run_command('sh', '-c', 'echo $POS_BUILD_ENABLE_RUNTIME_DEBUG_CHECK').stdout().strip().to_int()
if enable_runtime_debug_check != 0 and enable_runtime_debug_check != 1
    assert(
        false, 
        'enable_runtime_debug_check get invalid value: ' + enable_runtime_debug_check.to_string()
    )
endif

# switch:   whether to print all fatal messages
enable_print_error = run_command('sh', '-c', 'echo $POS_BUILD_ENABLE_PRINT_ERROR').stdout().strip().to_int()
if enable_print_error != 0 and enable_print_error != 1
    assert(
        false, 
        'enable_print_error get invalid value: ' + enable_print_error.to_string()
    )
endif

# switch:   whether to print all warning messages
enable_print_warn = run_command('sh', '-c', 'echo $POS_BUILD_ENABLE_PRINT_WARN').stdout().strip().to_int()
if enable_print_warn != 0 and enable_print_warn != 1
    assert(
        false, 
        'enable_print_warn get invalid value: ' + enable_print_warn.to_string()
    )
endif

# switch:   whether to print all log messages
enable_print_log = run_command('sh', '-c', 'echo $POS_BUILD_ENABLE_PRINT_LOG').stdout().strip().to_int()
if enable_print_log != 0 and enable_print_log != 1
    assert(
        false, 
        'enable_print_log get invalid value: ' + enable_print_log.to_string()
    )
endif

# switch:   whether to print all debug messages
enable_print_debug = run_command('sh', '-c', 'echo $POS_BUILD_ENABLE_PRINT_DEBUG').stdout().strip().to_int()
if enable_print_debug != 0 and enable_print_debug != 1
    assert(
        false, 
        'enable_print_debug get invalid value: ' + enable_print_debug.to_string()
    )
endif

# switch:   whether to print fatal/warn/debug/log with colors
#           should be disabled when try to dump all outputs to a file
enable_print_with_color = run_command('sh', '-c', 'echo $POS_BUILD_ENABLE_PRINT_WITH_COLOR').stdout().strip().to_int()
if enable_print_with_color != 0 and enable_print_with_color != 1
    assert(
        false, 
        'enable_print_with_color get invalid value: ' + enable_print_with_color.to_string()
    )
endif


# >>>>>>>>>>>>>> find target libraries >>>>>>>>>>>>>>
if target == 'cuda'
    # cuda_version = run_command(bash, '../scripts/utils/get_cuda_version.sh').stdout().strip()
    cuda_version = target_version
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
    message('>>> Detecting CUDA toolkit done\n')
endif


# >>>>>>>>>>>>>> setup sources, libraries and includes >>>>>>>>>>>>>>
inc_dirs += [ '../' ]
inc_dirs += [ googletest_rlt_path+'/googletest/include' ]
ld_args += [ '-L'+googletest_abs_path+'/build/lib' ]
ld_args += [ '-lgtest', '-lgtest_main' ]
if target == 'cuda'
    sources += run_command('python3', files(scan_src_path), 'test_cuda', check: false).stdout().strip().split('\n')
    ld_args += [ '-ldl', '-lpatcher', '-lclang', '-lrt', '-pthread', '-lelf', '-lpos', '-libverbs' ]
endif


# >>>>>>>>>>>>>> setup build options >>>>>>>>>>>>>>
c_args += ['--std=c++17']

executable(
    project_name_abbreviation,
    sources,
    cpp_args: c_args,
	link_args: ld_args,
	include_directories: inc_dirs,
	install: false
)
