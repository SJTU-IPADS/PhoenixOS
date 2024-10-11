project('test_cuda_patcher', ['CPP'])
project_name = 'test_cuda_patcher'
project_name_abbreviation = 'test_cuda_patcher'

# >>>>>>>>>>>>>> build prepare >>>>>>>>>>>>>>
# get environment variables of the build process
env = environment()

# we use pkg-config to collect dependecies
pkgconfig = find_program('pkg-config')
bash = find_program('bash')

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
meson_file_dir = meson.current_source_dir()
project_root_dir =  '../../../'

# >>>>>>>>>>>>>> find target libraries >>>>>>>>>>>>>>

# >>>>> 1. CUDA
# extract cuda version
get_cuda_version_script_path = project_root_dir + 'scripts/utils/get_cuda_version.sh'
cuda_version = run_command(bash, get_cuda_version_script_path).stdout().strip()
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

# >>>>> 2. patcher
message('>>> find library patcher')
# ldl is necessary
patcher_ld_args = ['-L' + project_root_dir + 'pos/cuda_impl/patcher/build/release', '-ldl', '-lpatcher']
patcher_inc_dirs = [project_root_dir + 'pos/cuda_impl/patcher/build']
ld_args += patcher_ld_args
inc_dirs += patcher_inc_dirs
message('>>> found patcher\n')

# >>>>> 3. for support shm_x
message('>>> Setup librt') 
ld_args += ['-lrt']
message('>>> Setup librt done\n')

# >>>>> 4. for support pthread_x
message('>>> Setup pthread')
ld_args += ['-pthread']
message('>>> Setup pthread done\n')

# >>>>> 5. for support elf_x
message('>>> Setup libelf')
ld_args += ['-lelf']
message('>>> Setup libelf done\n')

# >>>>>>>>>>>>>> setup sources and includes >>>>>>>>>>>>>>
sources += [
    './main.cc'
]
inc_dirs += ['./']

# >>>>>>>>>>>>>> setup build options >>>>>>>>>>>>>>
c_args += ['--std=c++17']

executable(
    project_name_abbreviation,
    sources,
    dependencies : deps,
	cpp_args: c_args,
	link_args: ld_args,
	include_directories: inc_dirs,
	install: false
)
