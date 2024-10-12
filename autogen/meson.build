# >>> project definition
project('PhoenixOS_Autogen', ['CPP'],
	# Get version number from file.
	version: run_command(find_program('cat'),files('../VERSION'), check: true).stdout().strip(),
)
project_name = 'phoenix_os_autogen'
project_name_abbreviation = 'pos_autogen'

add_project_arguments('-O0',  language : 'cpp')

scan_src_path = meson.current_source_dir() + '/../scripts/utils/glob_src.py'

# >>>>>>>>>>>>>> build prepare >>>>>>>>>>>>>>
# get environment variables of the build process
env = environment()

# we use pkg-config to collect dependecies
pkgconfig = find_program('pkg-config')
bash = find_program('bash')

# path of built libraries by PhOS build system
lib_path = meson.current_source_dir() + '/../lib'

# compile flags
c_args = []

# load flags
ld_args = [ '-L'+lib_path ]

# include directories
inc_dirs = [ '../lib', '../lib/pos/include', '../' ]

# source files
sources = []


# >>>>>>>>>>>>>> setup configurations >>>>>>>>>>>>>>
# config:   target selection (options: cuda, todos: rocm/ascend)
target = run_command('sh', '-c', 'echo $POS_BUILD_TARGET').stdout().strip()
if target != 'cuda'
    assert(false, 'target ' + target + ' is currently not supported')
endif



# >>>>>>>>>>>>>> find target libraries >>>>>>>>>>>>>>
if target == 'cuda'
    # extract cuda version
    cuda_version = run_command(bash, '../scripts/utils/get_cuda_version.sh').stdout().strip()
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
sources += [ 'autogen_common.cpp', 'autogen_cpp.cpp', 'main.cpp', 'utils.cpp' ]
inc_dirs += [ '../' ]
ld_args += [ '-lclang', '-lyaml-cpp' ]
if target == 'cuda'
    sources += run_command('python3', files(scan_src_path), 'autogen_cuda', check: false).stdout().strip().split('\n')
    # ld_args += [ '-ldl', '-lpatcher', '-lrt', '-pthread', '-lelf', '-lpos', '-libverbs' ]
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
