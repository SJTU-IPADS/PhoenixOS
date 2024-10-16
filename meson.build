# >>> project definition
project('PhoenixOS', ['CPP'],
	# Get version number from file.
	version: run_command(find_program('cat'),files('./VERSION'), check: true).stdout().strip(),
)
project_name = 'phoenix_os'
project_name_abbreviation = 'pos'

add_project_arguments('-O0',  language : 'cpp')

# >>>>>>>>>>>>>> build prepare >>>>>>>>>>>>>>
# get environment variables of the build process
env = environment()

# we use pkg-config to collect dependecies
pkgconfig = find_program('pkg-config')
bash = find_program('bash')

# path of built libraries by PhOS build system
lib_path = meson.current_source_dir() + '/lib'

# compile flags
c_args = []

# load flags
ld_args = [ '-L'+lib_path ]

# dependencies
deps = []

# include directories
inc_dirs = [ 'lib', 'lib/pos/include' ]

# all libraries that want to be statically linked
libraries = []

# source files
sources = []

# current directory of this meson file
meson_file_dir = meson.current_source_dir()


# >>>>>>>>>>>>>> setup configurations >>>>>>>>>>>>>>
# target selection (options: cuda, todos: rocm/ascend)
conf_runtime_target = run_command('sh', '-c', 'echo $POS_BUILD_CONF_RuntimeTarget').stdout().strip()
if conf_runtime_target != 'cuda'
    assert(false, 'runtime target ' + conf_runtime_target + ' is currently not supported')
endif

# target version (example: "11.3" for CUDA 11.3)
conf_runtime_target_version = run_command('sh', '-c', 'echo $POS_BUILD_CONF_RuntimeTargetVersion').stdout().strip()
if conf_runtime_target_version == ''
    assert(false, 'no runtime target version was provided')
endif

# checkpoint optimization level
#   - 0: no ckpt support
#   - 1: naive ckpt support
#   - 2: pos ckpt support
conf_eval_ckpt_opt_level = run_command('sh', '-c', 'echo $POS_BUILD_CONF_EvalCkptOptLevel').stdout().strip().to_int()
if conf_eval_ckpt_opt_level != 0 and conf_eval_ckpt_opt_level != 1 and conf_eval_ckpt_opt_level != 2
    assert(false, 'conf_eval_ckpt_opt_level with level ' + conf_eval_ckpt_opt_level.to_string() + ' is currently not supported')
endif

# migration optimization level
#   - 0: no migration support
#   - 1: naive migration support
#   - 2: pos migration support
conf_eval_migr_opt_level = run_command('sh', '-c', 'echo $POS_BUILD_CONF_EvalMigrOptLevel').stdout().strip().to_int()
if conf_eval_migr_opt_level != 0 and conf_eval_migr_opt_level != 1 and conf_eval_migr_opt_level != 2
    assert(false, 'conf_eval_migr_opt_level with level ' + conf_eval_migr_opt_level.to_string() + ' is currently not supported')
endif

# >>>>>>>>>>>>>> find target libraries >>>>>>>>>>>>>>
if conf_runtime_target == 'cuda'
    # cuda_version = run_command(bash, './scripts/utils/get_cuda_version.sh').stdout().strip()
    cuda_version = conf_runtime_target_version
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


# >>>>>>>>>>>>>> setup sources and includes >>>>>>>>>>>>>>
sources += [
    'pos/src/handle.cpp',
    'pos/src/api_context.cpp',
    'pos/src/client.cpp',
    'pos/src/worker.cpp',
    'pos/src/parser.cpp',
    'pos/src/workspace.cpp',
    'pos/src/migration.cpp',
    'pos/src/oob/agent.cpp',
    'pos/src/oob/cli.cpp',
    'pos/src/oob/utils.cpp',
    'pos/src/oob/migration.cpp',
    'pos/src/oob/mgnt.cpp'
]

if conf_eval_ckpt_opt_level == 0
    if conf_eval_migr_opt_level == 0
        sources += ['pos/src/checkpoint_o0.cpp']
    else
        sources += ['pos/src/checkpoint_o1.cpp']
    endif
elif conf_eval_ckpt_opt_level == 1
    sources += ['pos/src/checkpoint_o1.cpp']
elif conf_eval_ckpt_opt_level == 2
    sources += ['pos/src/checkpoint_o2.cpp']
endif

if conf_runtime_target == 'cuda'
    sources += [
        'pos/cuda_impl/api_context.cpp',
        'pos/cuda_impl/utils/fatbin.cpp',
        'pos/cuda_impl/parser/cublas.cpp',
        'pos/cuda_impl/parser/cuda_driver.cpp',
        'pos/cuda_impl/parser/cuda_runtime.cpp',
        'pos/cuda_impl/parser/remoting.cpp',
        'pos/cuda_impl/worker/cublas.cpp',
        'pos/cuda_impl/worker/cuda_driver.cpp',
        'pos/cuda_impl/worker/cuda_runtime.cpp',
        'pos/cuda_impl/handle/memory.cpp'
    ]
endif

inc_dirs += ['./']


# >>>>>>>>>>>>>> setup third party dependencies >>>>>>>>>>>>>>
if conf_runtime_target == 'cuda'
    ld_args += ['-ldl', '-lpatcher']    # for cuda patcher
    ld_args += ['-lclang']              # for using libclang for cuda target
    ld_args += ['-lrt']                 # for support shm_x
    ld_args += ['-pthread']             # for support pthread_x
    ld_args += ['-lelf']                # for support elf_x
endif


# >>>>>>>>>>>>>> setup build options >>>>>>>>>>>>>>
c_args += ['--std=c++17']


# >>>>>>>>>>>>>> start building >>>>>>>>>>>>>>
# libpos.so
libpos = library(
    project_name_abbreviation,
    sources,
	dependencies : deps,
	cpp_args: c_args,
	link_args: ld_args,
	include_directories: inc_dirs,
	install: false
)
