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


# >>>>>> [1] platform configs >>>>>>>>
# root directory of the project
conf_platform_project_root = run_command('sh', '-c', 'echo $POS_BUILD_CONF_PlatformProjectRoot').stdout().strip()
if conf_platform_project_root == ''
    assert(false, 'no project root directory was set')
endif
# >>>>>>>> [1] platform configs >>>>>>>>


# >>>>>>>> [2] runtime configs >>>>>>>>
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

# whether to print all fatal messages
conf_runtime_enable_print_error = run_command('sh', '-c', 'echo $POS_BUILD_CONF_RuntimeEnablePrintError').stdout().strip().to_int()
if conf_runtime_enable_print_error != 0 and conf_runtime_enable_print_error != 1
    assert(
        false, 
        'conf_runtime_enable_print_error get invalid value: ' + conf_runtime_enable_print_error.to_string()
    )
endif

# whether to print all warning messages
conf_runtime_enable_print_warn = run_command('sh', '-c', 'echo $POS_BUILD_CONF_RuntimeEnablePrintWarn').stdout().strip().to_int()
if conf_runtime_enable_print_warn != 0 and conf_runtime_enable_print_warn != 1
    assert(
        false,
        'conf_runtime_enable_print_warn get invalid value: ' + conf_runtime_enable_print_warn.to_string()
    )
endif

# whether to print all log messages
conf_runtime_enable_print_log = run_command('sh', '-c', 'echo $POS_BUILD_CONF_RuntimeEnablePrintLog').stdout().strip().to_int()
if conf_runtime_enable_print_log != 0 and conf_runtime_enable_print_log != 1
    assert(
        false, 
        'conf_runtime_enable_print_log get invalid value: ' + conf_runtime_enable_print_log.to_string()
    )
endif

# whether to print all debug messages
conf_runtime_enable_print_debug = run_command('sh', '-c', 'echo $POS_BUILD_CONF_RuntimeEnablePrintDebug').stdout().strip().to_int()
if conf_runtime_enable_print_debug != 0 and conf_runtime_enable_print_debug != 1
    assert(
        false, 
        'conf_runtime_enable_print_debug get invalid value: ' + conf_runtime_enable_print_debug.to_string()
    )
endif

# whether to print fatal/warn/debug/log with colors
# should be disabled when try to dump all outputs to a file
conf_runtime_enable_print_with_color = run_command('sh', '-c', 'echo $POS_BUILD_CONF_RuntimeEnablePrintWithColor').stdout().strip().to_int()
if conf_runtime_enable_print_with_color != 0 and conf_runtime_enable_print_with_color != 1
    assert(
        false, 
        'conf_runtime_enable_print_with_color get invalid value: ' + conf_runtime_enable_print_with_color.to_string()
    )
endif

# whether to check correctness of function parameters, return values, etc.,
# which might cause extra runtime burden, should only be enabled while debuging
conf_runtime_enable_debug_check = run_command('sh', '-c', 'echo $POS_BUILD_CONF_RuntimeEnableDebugCheck').stdout().strip().to_int()
if conf_runtime_enable_debug_check != 0 and conf_runtime_enable_debug_check != 1
    assert(
        false,
        'conf_runtime_enable_debug_check get invalid value: ' + conf_runtime_enable_debug_check.to_string()
    )
endif

# whether to check whether POS finish the hijacking logic of called APIs,
# which might cause extra runtime burden, should only be enabled while debuging
conf_runtime_enable_hijack_api_check = run_command('sh', '-c', 'echo $POS_BUILD_CONF_RuntimeEnableHijackApiCheck').stdout().strip().to_int()
if conf_runtime_enable_hijack_api_check != 0 and conf_runtime_enable_hijack_api_check != 1
    assert(
        false, 
        'conf_runtime_enable_hijack_api_check get invalid value: ' + conf_runtime_enable_hijack_api_check.to_string()
    )
endif

# whether to trace the statistics
conf_runtime_enable_trace = run_command('sh', '-c', 'echo $POS_BUILD_CONF_RuntimeEnableTrace').stdout().strip().to_int()
if conf_runtime_enable_trace != 0 and conf_runtime_enable_trace != 1
    assert(
        false, 
        'conf_runtime_enable_trace get invalid value: ' + conf_runtime_enable_trace.to_string()
    )
endif

# log path of PhOS daemon
conf_runtime_default_daemon_log_path = run_command('sh', '-c', 'echo $POS_BUILD_CONF_RuntimeDefaultDaemonLogPath').stdout().strip()
if conf_runtime_default_daemon_log_path == ''
    assert(false, 'no default log path of PhOS daemon is provided')
endif

# log path of PhOS client
conf_runtime_default_client_log_path = run_command('sh', '-c', 'echo $POS_BUILD_CONF_RuntimeDefaultClientLogPath').stdout().strip()
if conf_runtime_default_client_log_path == ''
    assert(false, 'no default log path of PhOS client is provided')
endif
# >>>>>>>> [2] runtime configs >>>>>>>>


# >>>>>>>> [3] evaluation configs >>>>>>>>
# checkpoint optimization level
#   - 0: no ckpt support
#   - 1: naive ckpt support
#   - 2: pos ckpt support
conf_eval_ckpt_opt_level = run_command('sh', '-c', 'echo $POS_BUILD_CONF_EvalCkptOptLevel').stdout().strip().to_int()
if conf_eval_ckpt_opt_level != 0 and conf_eval_ckpt_opt_level != 1 and conf_eval_ckpt_opt_level != 2
    assert(false, 'conf_eval_ckpt_opt_level with level ' + conf_eval_ckpt_opt_level.to_string() + ' is currently not supported')
endif

# sync/async checkpoint (level 1,2) optimization -> flag to control increamental checkpoint
conf_eval_ckpt_enable_increamental = run_command('sh', '-c', 'echo $POS_BUILD_CONF_EvalCkptEnableIncremental').stdout().strip().to_int()
if conf_eval_ckpt_enable_increamental != 0 and conf_eval_ckpt_enable_increamental != 1
    assert(
        false,
        'conf_eval_ckpt_enable_increamental get invalid value: ' + conf_eval_ckpt_enable_increamental.to_string()
    )
endif

# async checkpoint (level 2) optimization -> flag to control checkpoint pipeline
conf_eval_ckpt_enable_pipeline = run_command('sh', '-c', 'echo $POS_BUILD_CONF_EvalCkptEnablePipeline').stdout().strip().to_int()
if conf_eval_ckpt_enable_pipeline != 0 and conf_eval_ckpt_enable_pipeline != 1
    assert(
        false,
        'conf_eval_ckpt_enable_pipeline get invalid value: ' + conf_eval_ckpt_enable_pipeline.to_string()
    )
endif

# default continuous checkpoint interval (unit in ms)
conf_eval_default_ckpt_interval_ms = run_command('sh', '-c', 'echo $POS_BUILD_CONF_EvalCkptDefaultIntervalMs').stdout().strip().to_int()
if conf_eval_default_ckpt_interval_ms < 0
    assert(
        false,
        'conf_eval_default_ckpt_interval_ms get invalid value: ' + conf_eval_default_ckpt_interval_ms.to_string()
    )
endif

# migration optimization level
#   - 0: no migration support
#   - 1: naive migration support
#   - 2: pos migration support
conf_eval_migr_opt_level = run_command('sh', '-c', 'echo $POS_BUILD_CONF_EvalMigrOptLevel').stdout().strip().to_int()
if conf_eval_migr_opt_level != 0 and conf_eval_migr_opt_level != 1 and conf_eval_migr_opt_level != 2
    assert(false, 'conf_eval_migr_opt_level with level ' + conf_eval_migr_opt_level.to_string() + ' is currently not supported')
endif

# whether to enable context pool to restore
conf_eval_rst_enable_context_pool = run_command('sh', '-c', 'echo $POS_BUILD_CONF_EvalRstEnableContextPool').stdout().strip().to_int()
if conf_eval_rst_enable_context_pool != 0 and conf_eval_rst_enable_context_pool != 1 and conf_eval_rst_enable_context_pool != 2
    assert(false, 'conf_eval_rst_enable_context_pool with level ' + conf_eval_rst_enable_context_pool.to_string() + ' is currently not supported')
endif
# >>>>>>>> [3] evaluation configs >>>>>>>>


# add common headers
subdir('pos/include')

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
    # common source files
    'pos/src/agent.cpp',
    'pos/src/handle.cpp',
    'pos/src/api_context.cpp',
    'pos/src/client.cpp',
    'pos/src/worker.cpp',
    'pos/src/parser.cpp',
    'pos/src/workspace.cpp',

    # oob functions
    'pos/src/oob/agent.cpp',
    'pos/src/oob/cli.cpp',
    'pos/src/oob/utils.cpp',
    'pos/src/oob/ckpt_predump.cpp',
    'pos/src/oob/ckpt_dump.cpp',
    'pos/src/oob/restore.cpp',
    'pos/src/oob/trace.cpp',
    'pos/src/oob/migration.cpp',
    'pos/src/oob/mgnt.cpp',

    # protobuf generated file
    'pos/include/proto/client.pb.cc',
    'pos/include/proto/handle.pb.cc',
    'pos/include/proto/apicxt.pb.cc'
]

if conf_eval_ckpt_opt_level == 0
    sources += ['pos/src/checkpoint_disable.cpp']
else
    sources += ['pos/src/checkpoint_enable.cpp']
endif

if conf_runtime_target == 'cuda'
    sources += [
        # common source files
        'pos/cuda_impl/src/api_context.cpp',
        'pos/cuda_impl/src/workspace.cpp',
        'pos/cuda_impl/src/handle.cpp',
        'pos/cuda_impl/src/client.cpp',
        'pos/cuda_impl/src/utils/fatbin.cpp',

        # parser functions
        'pos/cuda_impl/src/parser/cublas.cpp',
        'pos/cuda_impl/src/parser/cuda_driver.cpp',
        'pos/cuda_impl/src/parser/cuda_runtime.cpp',
        'pos/cuda_impl/src/parser/remoting.cpp',

        # worker functions
        'pos/cuda_impl/src/worker/cublas.cpp',
        'pos/cuda_impl/src/worker/cuda_driver.cpp',
        'pos/cuda_impl/src/worker/cuda_runtime.cpp',

        # cuda handles
        'pos/cuda_impl/src/handle/context.cpp',
        'pos/cuda_impl/src/handle/cublas.cpp',
        'pos/cuda_impl/src/handle/device.cpp',
        'pos/cuda_impl/src/handle/event.cpp',
        'pos/cuda_impl/src/handle/function.cpp',
        'pos/cuda_impl/src/handle/memory.cpp',
        'pos/cuda_impl/src/handle/module.cpp',
        'pos/cuda_impl/src/handle/stream.cpp',
        'pos/cuda_impl/src/handle/var.cpp',

        # protobuf generated file
        'pos/cuda_impl/proto/context.pb.cc',
        'pos/cuda_impl/proto/cublas.pb.cc',
        'pos/cuda_impl/proto/device.pb.cc',
        'pos/cuda_impl/proto/event.pb.cc',
        'pos/cuda_impl/proto/function.pb.cc',
        'pos/cuda_impl/proto/memory.pb.cc',
        'pos/cuda_impl/proto/module.pb.cc',
        'pos/cuda_impl/proto/stream.pb.cc',
        'pos/cuda_impl/proto/var.pb.cc'
    ]
endif

inc_dirs += ['./']

# >>>>>>>>>>>>>> setup third party dependencies >>>>>>>>>>>>>>
ld_args += ['-lyaml-cpp']                   # for loading client-side configurations
ld_args += ['-pthread']                     # for support pthread_x
ld_args += ['-libverbs']                    # for migration
ld_args += ['-luuid']                       # for uuid support

# for protobuf
ld_args += ['-lprotobuf', '-lprotobuf-lite', '-lprotoc']                   

if conf_runtime_target == 'cuda'
    ld_args += ['-ldl', '-lpatcher']    # for cuda patcher
    ld_args += ['-lclang']              # for using libclang for cuda target
    ld_args += ['-lrt']                 # for support shm_x
    ld_args += ['-lelf']                # for support elf_x
endif

inc_dirs += ['./third_party/protobuf/src']  # for protobuf

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
