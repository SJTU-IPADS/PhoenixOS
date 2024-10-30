package main

import (
	"fmt"

	"github.com/charmbracelet/log"
)

func CRIB_PhOS_Core(cmdOpt CmdOptions, buildConf BuildConfigs, logger *log.Logger) {
	build_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		{{.__CMD_EXPRORT_ENV_VAR__}}
		cd %s
		rm -rf ./build

		# protobuf generation
		./bin/protoc --proto_path=. --cpp_out=. pos/include/proto/*.proto pos/cuda_impl/proto/*.proto &>{{.__LOG_PATH__}} 2>&1

		# build core
		meson build >{{.__LOG_PATH__}} 2>&1
		cd build
		ninja clean >{{.__LOG_PATH__}} 2>&1
		ninja >{{.__LOG_PATH__}} 2>&1
		cp ./build/libpos.so {{.__LOCAL_LIB_PATH__}} >{{.__LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir,
	)

	install_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		cd %s
		cp ./build/libpos.so {{.__SYSTEM_LIB_PATH__}} >{{.__LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir,
	)

	clean_script := fmt.Sprintf(`
		#!/bin/bash
		cd %s
		rm -rf build >{{.__LOG_PATH__}} 2>&1
		# clean local installation
		rm -rf {{.__LOCAL_LIB_PATH__}}/libpos.so >{{.__LOG_PATH__}} 2>&1
		# clean system installation
		rm -rf {{.__SYSTEM_LIB_PATH__}}/libpos.so >{{.__LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir,
	)

	unitOpt := UnitOptions{
		Name:          "PhOS-Core",
		BuildScript:   build_script,
		RunScript:     "",
		InstallScript: install_script,
		CleanScript:   clean_script,
		DoBuild:       *cmdOpt.DoBuild,
		DoRun:         false,
		DoInstall:     *cmdOpt.DoInstall,
		DoClean:       *cmdOpt.DoClean,
	}
	ExecuteCRIB(cmdOpt, buildConf, unitOpt, logger)
}

func CRIB_PhOS_CLI(cmdOpt CmdOptions, buildConf BuildConfigs, logger *log.Logger) {
	build_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		{{.__CMD_EXPRORT_ENV_VAR__}}
		cd %s/%s

		# copy common headers
		rm -rf ./pos/include
		mkdir -p ./pos/include
		{{.__CMD_COPY_COMMON_HEADER__}}

		rm -rf build
		meson build >{{.__LOG_PATH__}} 2>&1
		cd build
		ninja  >{{.__LOG_PATH__}} 2>&1
		cp ./pos_cli {{.__LOCAL_BIN_PATH__}} >{{.__LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, KPhOSCLIPath,
	)

	install_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		cd %s/%s
		cp ./build/pos_cli {{.__SYSTEM_BIN_PATH__}} >{{.__LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, KPhOSCLIPath,
	)

	clean_script := fmt.Sprintf(`
		#!/bin/bash
		cd %s/%s
		rm -rf build
		# clean local installation
		rm -rf {{.__LOCAL_BIN_PATH__}}/pos_cli
		# clean system installation
		rm -rf {{.__SYSTEM_BIN_PATH__}}/pos_cli
		`,
		cmdOpt.RootDir, KPhOSCLIPath,
	)

	unitOpt := UnitOptions{
		Name:          "PhOS-CLI",
		BuildScript:   build_script,
		RunScript:     "",
		InstallScript: install_script,
		CleanScript:   clean_script,
		DoBuild:       *cmdOpt.DoBuild,
		DoRun:         false,
		DoInstall:     *cmdOpt.DoInstall,
		DoClean:       *cmdOpt.DoClean,
	}
	ExecuteCRIB(cmdOpt, buildConf, unitOpt, logger)
}

func CRIB_PhOS_UnitTest(cmdOpt CmdOptions, buildConf BuildConfigs, logger *log.Logger) {
	build_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		{{.__CMD_EXPRORT_ENV_VAR__}}
		cd %s/%s

		# copy common headers
		rm -rf ./pos/include
		mkdir -p ./pos/include
		{{.__CMD_COPY_COMMON_HEADER__}}

		rm -rf ./build
		meson build >{{.__LOG_PATH__}} 2>&1
		cd build
		ninja clean
		ninja >{{.__LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, kPhOSUnitTestPath,
	)

	run_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		cd %s/%s/build
		LD_LIBRARY_PATH=../../lib/ ./pos_test >{{.__LOG_PATH__}} 2&>1
		`,
		cmdOpt.RootDir, kPhOSUnitTestPath,
	)

	clean_script := fmt.Sprintf(`
		#!/bin/bash
		cd %s/%s
		rm -rf build
		rm -rf pos/include
		`,
		cmdOpt.RootDir, kPhOSUnitTestPath,
	)

	unitOpt := UnitOptions{
		Name:          "PhOS-CLI",
		BuildScript:   build_script,
		RunScript:     run_script,
		InstallScript: "",
		CleanScript:   clean_script,
		DoBuild:       *cmdOpt.DoBuild,
		DoRun:         true,
		DoInstall:     *cmdOpt.DoInstall,
		DoClean:       *cmdOpt.DoClean,
	}
	ExecuteCRIB(cmdOpt, buildConf, unitOpt, logger)
}
