package main

import (
	"fmt"

	"github.com/PhoenixOS-IPADS/PhOS/scripts/utils"
	"github.com/charmbracelet/log"
)

const (
	KGoogleTestPath = "third_party/googletest"
)

type BuildOptions struct {
	RootDir        string
	WithThirdParty *bool
	Target         *string
	PrintHelp      *bool
	DoCleaning     *bool
	DoInstall      *bool
	DoUnitTest     *bool
}

func (bo *BuildOptions) print(logger *log.Logger) {

}

func BuildGoogleTest(bo BuildOptions, logger *log.Logger) {
	logger.Infof("building googletest...")

	buildLogPath := fmt.Sprintf("%s/%s/%s", bo.RootDir, KBuildLogPath, "build_googletest.log")
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
		bo.RootDir, KGoogleTestPath,
		buildLogPath,
		buildLogPath,
	)

	_, err := utils.BashScriptGetOutput(build_script, false, logger)
	if err != nil {
		logger.Fatalf("failed to build googletest, please see log at %s", buildLogPath)
	}
	logger.Infof("built googletest")
}

func CleanGoogleTest(bo BuildOptions, logger *log.Logger) {
	logger.Infof("cleaning googletest...")
	clean_script := fmt.Sprintf(`
		#!/bin/bash
		cd %s/%s
		rm -rf build
		`,
		bo.RootDir, KGoogleTestPath,
	)
	_, err := utils.BashScriptGetOutput(clean_script, true, logger)
	if err != nil {
		logger.Warnf("failed to clean googletest")
	}
	logger.Infof("done")
}
