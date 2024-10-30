package main

import (
	"os"
	"fmt"
	"strings"
	"text/template"
	"time"

	"github.com/PhoenixOS-IPADS/PhOS/scripts/utils"
	"github.com/charmbracelet/log"
)

const (
	KGoogleTestPath = "third_party/googletest"

	// generated directories path
	KLogPath      = "build_log"
	KBuildLibPath = "lib"
	KBuildIncPath = "lib/pos/include"
	KBuildBinPath = "bin"

	// system path
	KInstallLibPath = "/lib/x86_64-linux-gnu"
	KInstallIncPath = "/usr/local/include"
	KInstallBinPath = "/usr/local/bin"

	// PhOS path
	KPhOSPath         = "pos"
	KPhOSCLIPath      = "pos/cli"
	kPhOSUnitTestPath = "unittest"
)

type UnitOptions struct {
	Name          string
	BuildScript   string
	InstallScript string
	RunScript     string
	CleanScript   string
	DoBuild       bool
	DoRun         bool
	DoInstall     bool
	DoClean       bool
}

type CmdOptions struct {
	RootDir        string
	WithThirdParty bool
	WithUnitTest   bool
	Target         string
	PrintHelp      bool
	DoBuild        bool
	DoInstall      bool
	DoClean        bool
}

func (cmdOpt *CmdOptions) print(logger *log.Logger) {
	print_str := fmt.Sprintf(
		`
			- RootDir: %v
			- WithThirdParty: %v
			- Target: %v
			- PrintHelp: %v
			- DoClean: %v
			- DoInstall: %v
			- WithUnitTest: %v
		`,
		cmdOpt.RootDir,
		cmdOpt.WithThirdParty,
		cmdOpt.Target,
		cmdOpt.PrintHelp,
		cmdOpt.DoClean,
		cmdOpt.DoInstall,
		cmdOpt.WithUnitTest,
	)
	logger.Infof("Commandline options: %s", print_str)
}

type BuildConfigs struct {
	// Platform Options
	PlatformProjectRoot string

	// Runtime Options
	RuntimeTarget               string `yaml:"runtime_target"`
	RuntimeTargetVersion        string `yaml:"runtime_target_version"`
	RuntimeEnablePrintError     uint8  `yaml:"runtime_enable_print_error"`
	RuntimeEnablePrintWarn      uint8  `yaml:"runtime_enable_print_warn"`
	RuntimeEnablePrintLog       uint8  `yaml:"runtime_enable_print_log"`
	RuntimeEnablePrintDebug     uint8  `yaml:"runtime_enable_print_debug"`
	RuntimeEnablePrintWithColor uint8  `yaml:"runtime_enable_print_with_color"`
	RuntimeEnableDebugCheck     uint8  `yaml:"runtime_enable_debug_check"`
	RuntimeEnableHijackApiCheck uint8  `yaml:"runtime_enable_hijack_api_check"`
	RuntimeEnableTrace          uint8  `yaml:"runtime_enable_trace"`
	RuntimeDefaultDaemonLogPath string `yaml:"runtime_default_daemon_log_path"`
	RuntimeDefaultClientLogPath string `yaml:"runtime_default_client_log_path"`

	// Evaluation Options
	// checkpoint
	EvalCkptOptLevel          uint8  `yaml:"eval_ckpt_opt_level"`
	EvalCkptEnableIncremental uint8  `yaml:"eval_ckpt_enable_incremental"`
	EvalCkptEnablePipeline    uint8  `yaml:"eval_ckpt_enable_pipeline"`
	EvalCkptDefaultIntervalMs uint32 `yaml:"eval_ckpt_interval_ms"`
	// migration
	EvalMigrOptLevel uint8 `yaml:"migr_interval_ms"`
	// restore
	EvalRstEnableContextPool uint8 `yaml:"eval_rst_enable_context_pool"`
}

func (buildConf *BuildConfigs) init(logger *log.Logger) {
	// obtain project root
	project_root, _ := utils.BashCommandGetOutput("bash ../utils/get_root_dir.sh", false, logger)
	buildConf.PlatformProjectRoot = string(project_root)
}

func (buildConf *BuildConfigs) print(logger *log.Logger) {
	print_str := fmt.Sprintf(
		`
		> Platform Configs:
			- PlatformProjectRoot: %v
		> Runtime Configs:
			- RuntimeTarget: %v
			- RuntimeTargetVersion: %v
			- RuntimeEnablePrintError: %v
			- RuntimeEnablePrintWarn: %v
			- RuntimeEnablePrintLog: %v
			- RuntimeEnablePrintDebug: %v
			- RuntimeEnablePrintWithColor: %v
			- RuntimeEnableDebugCheck: %v
			- RuntimeEnableHijackApiCheck: %v
			- RuntimeEnableTrace: %v
			- RuntimeDaemonLogPath: %v
			- RuntimeClientLogPath: %v
		> Evaluation Configs:
			- EvalCkptOptLevel: %v
			- EvalCkptEnableIncremental: %v
			- EvalCkptEnablePipeline: %v
			- EvalCkptInteralMs: %v
			- EvalMigrOptLevel: %v
			- EvalRstEnableContextPool: %v
		`,
		buildConf.PlatformProjectRoot,
		buildConf.RuntimeTarget,
		buildConf.RuntimeTargetVersion,
		buildConf.RuntimeEnablePrintError,
		buildConf.RuntimeEnablePrintWarn,
		buildConf.RuntimeEnablePrintLog,
		buildConf.RuntimeEnablePrintDebug,
		buildConf.RuntimeEnablePrintWithColor,
		buildConf.RuntimeEnableDebugCheck,
		buildConf.RuntimeEnableHijackApiCheck,
		buildConf.RuntimeEnableTrace,
		buildConf.RuntimeDefaultDaemonLogPath,
		buildConf.RuntimeDefaultClientLogPath,
		buildConf.EvalCkptOptLevel,
		buildConf.EvalCkptEnableIncremental,
		buildConf.EvalCkptEnablePipeline,
		buildConf.EvalCkptDefaultIntervalMs,
		buildConf.EvalMigrOptLevel,
		buildConf.EvalRstEnableContextPool,
	)
	logger.Infof("Build Configs: %s", print_str)
}

func (buildConf *BuildConfigs) export_string() string {
	return fmt.Sprintf(
		`
		# platform configs
		export POS_BUILD_CONF_PlatformProjectRoot=%v
		
		# runtime build configs
		export POS_BUILD_CONF_RuntimeTarget=%v
		export POS_BUILD_CONF_RuntimeTargetVersion=%v
		export POS_BUILD_CONF_RuntimeEnablePrintError=%v
		export POS_BUILD_CONF_RuntimeEnablePrintWarn=%v
		export POS_BUILD_CONF_RuntimeEnablePrintLog=%v
		export POS_BUILD_CONF_RuntimeEnablePrintDebug=%v
		export POS_BUILD_CONF_RuntimeEnablePrintWithColor=%v
		export POS_BUILD_CONF_RuntimeEnableDebugCheck=%v
		export POS_BUILD_CONF_RuntimeEnableHijackApiCheck=%v
		export POS_BUILD_CONF_RuntimeEnableTrace=%v
		export POS_BUILD_CONF_RuntimeDefaultDaemonLogPath=%v
		export POS_BUILD_CONF_RuntimeDefaultClientLogPath=%v

		# PhOS core build configs
		export POS_BUILD_CONF_EvalCkptOptLevel=%v
		export POS_BUILD_CONF_EvalCkptEnableIncremental=%v
		export POS_BUILD_CONF_EvalCkptEnablePipeline=%v
		export POS_BUILD_CONF_EvalCkptDefaultIntervalMs=%v
		export POS_BUILD_CONF_EvalMigrOptLevel=%v
		export POS_BUILD_CONF_EvalRstEnableContextPool=%v
		`,
		buildConf.PlatformProjectRoot,

		buildConf.RuntimeTarget,
		buildConf.RuntimeTargetVersion,
		buildConf.RuntimeEnablePrintError,
		buildConf.RuntimeEnablePrintWarn,
		buildConf.RuntimeEnablePrintLog,
		buildConf.RuntimeEnablePrintDebug,
		buildConf.RuntimeEnablePrintWithColor,
		buildConf.RuntimeEnableDebugCheck,
		buildConf.RuntimeEnableHijackApiCheck,
		buildConf.RuntimeEnableTrace,
		buildConf.RuntimeDefaultDaemonLogPath,
		buildConf.RuntimeDefaultClientLogPath,

		buildConf.EvalCkptOptLevel,
		buildConf.EvalCkptEnableIncremental,
		buildConf.EvalCkptEnablePipeline,
		buildConf.EvalCkptDefaultIntervalMs,
		buildConf.EvalMigrOptLevel,
		buildConf.EvalRstEnableContextPool,
	)
}

func ExecuteCRIB(cmdOpt CmdOptions, buildConf BuildConfigs, unitOpt UnitOptions, logger *log.Logger) {
	doPartial := func(script, logName string) float64 {
		var builder strings.Builder

		// check log file path
		if len(logName) == 0 {
			panic(fmt.Errorf("no log file name provided"))
		}
		logPath := fmt.Sprintf("%s/%s/%s", cmdOpt.RootDir, KLogPath, logName)

		// setup template
		t, err := template.New("").Parse(script)
		if err != nil {
			logger.Fatalf("failed to generate template")
		}
		script_data := struct {
			CMD_EXPRORT_ENV_VAR__    string
			CMD_COPY_COMMON_HEADER__ string
			LOG_PATH__               string
			LOCAL_LIB_PATH__         string
			LOCAL_BIN_PATH__         string
			LOCAL_INC_PATH__         string
			SYSTEM_LIB_PATH__        string
			SYSTEM_BIN_PATH__        string
			SYSTEM_INC_PATH__        string
		}{
			CMD_EXPRORT_ENV_VAR__: buildConf.export_string(),
			CMD_COPY_COMMON_HEADER__: fmt.Sprintf(`
				cp -r %s/%s/include/eval_configs.h.in ./pos/include/
				cp -r %s/%s/include/log.h.in ./pos/include/
				cp -r %s/%s/include/meson.build ./pos/include/
				cp -r %s/%s/include/runtime_configs.h.in ./pos/include/`,
				cmdOpt.RootDir, KPhOSPath,
				cmdOpt.RootDir, KPhOSPath,
				cmdOpt.RootDir, KPhOSPath,
				cmdOpt.RootDir, KPhOSPath,
			),
			LOG_PATH__:        logPath,
			LOCAL_LIB_PATH__:  fmt.Sprintf("%s/%s", cmdOpt.RootDir, KBuildLibPath),
			LOCAL_BIN_PATH__:  fmt.Sprintf("%s/%s", cmdOpt.RootDir, KBuildBinPath),
			LOCAL_INC_PATH__:  fmt.Sprintf("%s/%s", cmdOpt.RootDir, KBuildIncPath),
			SYSTEM_LIB_PATH__: KInstallLibPath,
			SYSTEM_BIN_PATH__: KInstallBinPath,
			SYSTEM_INC_PATH__: KInstallIncPath,
		}
		if err := t.Execute(&builder, script_data); err != nil {
			logger.Fatalf("failed to generate build script from template: %v", err)
		}
		
		// clean log file
		clean_log_script := fmt.Sprintf("echo \"\" > %s", logPath)
		_, err = utils.BashScriptGetOutput(clean_log_script, false, logger)
		if err != nil {
			logger.Fatalf("failed, failed to clean log content at %s before executing script", logName)
		}

		// execute script
		start := time.Now()
		_, err = utils.BashScriptGetOutput(builder.String(), false, logger)
		if err != nil {
			logger.Fatalf("failed, please see log at %s", logName)
		}
		elapsed := time.Since(start)

		return elapsed.Seconds()
	}

	if unitOpt.DoBuild && len(unitOpt.BuildScript) > 0 {
		logger.Infof("building %s...", unitOpt.Name)
		duration := doPartial(unitOpt.BuildScript, fmt.Sprintf("build_%s.log", unitOpt.Name))
		utils.ClearLastLine()
		logger.Infof("built %s: %.2fs", unitOpt.Name, duration)

		if unitOpt.DoRun && len(unitOpt.RunScript) > 0 {
			logger.Infof("running %s...", unitOpt.Name)
			duration := doPartial(unitOpt.CleanScript, fmt.Sprintf("run_%s.log", unitOpt.Name))
			utils.ClearLastLine()
			logger.Infof("ran %s: %.2fs", unitOpt.Name, duration)
		}
	}

	if unitOpt.DoInstall && len(unitOpt.InstallScript) > 0 {
		logger.Infof("installing %s...", unitOpt.Name)
		duration := doPartial(unitOpt.InstallScript, fmt.Sprintf("install_%s.log", unitOpt.Name))
		utils.ClearLastLine()
		logger.Infof("installed %s: %.2fs", unitOpt.Name, duration)
	}

	if unitOpt.DoClean && len(unitOpt.CleanScript) > 0 {
		logger.Infof("cleaning %s...", unitOpt.Name)
		duration := doPartial(unitOpt.CleanScript, fmt.Sprintf("clean_%s.log", unitOpt.Name))
		utils.ClearLastLine()
		logger.Infof("cleaned %s: %.2fs", unitOpt.Name, duration)
	}
}

func CRIB_PhOS(cmdOpt CmdOptions, buildConf BuildConfigs, logger *log.Logger) {
	buildLogPath := fmt.Sprintf("%s/%s", cmdOpt.RootDir, KLogPath)
	if err := utils.CreateDir(buildLogPath, true, 0775, logger); err != nil && !os.IsExist(err) {
		logger.Fatalf("failed to create directory for build logs at %s", buildLogPath)
	}

	libPath := fmt.Sprintf("%s/%s", cmdOpt.RootDir, KBuildLibPath)
	if err := utils.CreateDir(libPath, false, 0775, logger); err != nil && !os.IsExist(err) {
		logger.Fatalf("failed to create directory for built lib at %s", libPath)
	}

	includePath := fmt.Sprintf("%s/%s", cmdOpt.RootDir, KBuildIncPath)
	if err := utils.CreateDir(includePath, false, 0775, logger); err != nil && !os.IsExist(err) {
		logger.Fatalf("failed to create directory for built headers at %s", includePath)
	}

	binPath := fmt.Sprintf("%s/%s", cmdOpt.RootDir, KBuildBinPath)
	if err := utils.CreateDir(binPath, false, 0775, logger); err != nil && !os.IsExist(err) {
		logger.Fatalf("failed to create directory for built binary at %s", binPath)
	}

	if cmdOpt.Target == "cuda" {
		CRIB_PhOS_CUDA(cmdOpt, buildConf, logger)
	} else {
		log.Fatalf("Unsupported target %s", cmdOpt.Target)
	}
}
