package main

import (
	"fmt"

	"github.com/PhoenixOS-IPADS/PhOS/scripts/utils"
	"github.com/charmbracelet/log"
)

const (
	KGoogleTestPath = "third_party/googletest"
)

type CmdOptions struct {
	RootDir        string
	WithThirdParty *bool
	Target         *string
	PrintHelp      *bool
	DoCleaning     *bool
	DoInstall      *bool
	DoUnitTest     *bool
}

func (cmdOpt *CmdOptions) print(logger *log.Logger) {
	print_str := fmt.Sprintf(
		`
			- RootDir: %v
			- WithThirdParty: %v
			- Target: %v
			- PrintHelp: %v
			- DoCleaning: %v
			- DoInstall: %v
			- DoUnitTest: %v
		`,
		cmdOpt.RootDir,
		*cmdOpt.WithThirdParty,
		*cmdOpt.Target,
		*cmdOpt.PrintHelp,
		*cmdOpt.DoCleaning,
		*cmdOpt.DoInstall,
		*cmdOpt.DoUnitTest,
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
			- RuntimeDaemonLogPath: %v
			- RuntimeClientLogPath: %v
			- RuntimeEnablePrintError: %v
			- RuntimeEnablePrintWarn: %v
			- RuntimeEnablePrintLog: %v
			- RuntimeEnablePrintDebug: %v
			- RuntimeEnablePrintWithColor: %v
			- RuntimeEnableDebugCheck: %v
			- RuntimeEnableHijackApiCheck: %v
			- RuntimeEnableTrace: %v
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

func BuildGoogleTest(cmdOpt CmdOptions, buildConf BuildConfigs, logger *log.Logger) {
	logger.Infof("building googletest...")

	buildLogPath := fmt.Sprintf("%s/%s/%s", cmdOpt.RootDir, KBuildLogPath, "build_googletest.log")
	build_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		cd %s/%s
		if [ ! -d "./build" ] || [ ! -e "./build/lib/libgtest.a" ] || [ ! -e "./build/lib/libgtest_main.a" ]; then
			rm -rf build
			mkdir build && cd build
			cmake .. >%s 2>&1
			make -j >%s 2>&1
		fi
		`,
		cmdOpt.RootDir, KGoogleTestPath,
		buildLogPath,
		buildLogPath,
	)

	_, err := utils.BashScriptGetOutput(build_script, false, logger)
	if err != nil {
		logger.Fatalf("failed to build googletest, please see log at %s", buildLogPath)
	}
	logger.Infof("built googletest")
}

func CleanGoogleTest(cmdOpt CmdOptions, logger *log.Logger) {
	logger.Infof("cleaning googletest...")
	clean_script := fmt.Sprintf(`
		#!/bin/bash
		cd %s/%s
		rm -rf build
		`,
		cmdOpt.RootDir, KGoogleTestPath,
	)
	_, err := utils.BashScriptGetOutput(clean_script, true, logger)
	if err != nil {
		logger.Warnf("failed to clean googletest")
	}
	logger.Infof("done")
}
