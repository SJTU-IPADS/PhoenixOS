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

type BuildOptions struct {
	// common options
	Target               string `yaml:"target"`
	EnablePrintError     uint8  `yaml:"enable_print_error"`
	EnablePrintWarn      uint8  `yaml:"enable_print_warn"`
	EnablePrintLog       uint8  `yaml:"enable_print_log"`
	EnablePrintDebug     uint8  `yaml:"enable_print_debug"`
	EnablePrintWithColor uint8  `yaml:"enable_print_with_color"`

	// options for PhOS core
	CkptOptLevel            uint8 `yaml:"ckpt_opt_level"`
	EnableHijackApiCheck    uint8 `yaml:"enable_hijack_api_check"`
	EnableRuntimeDebugCheck uint8 `yaml:"enable_runtime_debug_check"`
}

func (buildOpt *BuildOptions) print(logger *log.Logger) {
	print_str := fmt.Sprintf(
		`
		> Common Build Options:
			- Target: %v
			- EnablePrintError: %v
			- EnablePrintWarn: %v
			- EnablePrintLog: %v
			- EnablePrintDebug: %v
			- EnablePrintWithColor: %v
		> PhOS Core Build Options:
			- CkptOptLevel: %v
			- EnableHijackApiCheck: %v
			- EnableRuntimeDebugCheck: %v
		`,
		buildOpt.Target,
		buildOpt.EnablePrintError,
		buildOpt.EnablePrintWarn,
		buildOpt.EnablePrintLog,
		buildOpt.EnablePrintDebug,
		buildOpt.EnablePrintWithColor,
		buildOpt.CkptOptLevel,
		buildOpt.EnableHijackApiCheck,
		buildOpt.EnableRuntimeDebugCheck,
	)
	logger.Infof("Build options: %s", print_str)
}

func (buildOpt *BuildOptions) export_string() string {
	return fmt.Sprintf(
		`# common build options
		export POS_BUILD_TARGET=%v
		export POS_BUILD_ENABLE_PRINT_ERROR=%v
		export POS_BUILD_ENABLE_PRINT_WARN=%v
		export POS_BUILD_ENABLE_PRINT_LOG=%v
		export POS_BUILD_ENABLE_PRINT_DEBUG=%v
		export POS_BUILD_ENABLE_PRINT_WITH_COLOR=%v
		# PhOS core build options
		export POS_BUILD_CHECKPOINTER_OPT_LEVEL=%v
		export POS_BUILD_ENABLE_HIJACK_API_CHECK=%v
		export POS_BUILD_ENABLE_RUNTIME_DEBUG_CHECK=%v
		`,
		buildOpt.Target,
		buildOpt.EnablePrintError,
		buildOpt.EnablePrintWarn,
		buildOpt.EnablePrintLog,
		buildOpt.EnablePrintDebug,
		buildOpt.EnablePrintWithColor,
		buildOpt.CkptOptLevel,
		buildOpt.EnableHijackApiCheck,
		buildOpt.EnableRuntimeDebugCheck,
	)
}

func BuildGoogleTest(cmdOpt CmdOptions, buildOpt BuildOptions, logger *log.Logger) {
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
