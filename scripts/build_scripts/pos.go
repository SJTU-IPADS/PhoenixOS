/*
 * Copyright 2025 The PhoenixOS Authors. All rights reserved.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package main

import (
	"fmt"
	"github.com/PhoenixOS-IPADS/PhOS/scripts/utils"
	"github.com/charmbracelet/log"
)

const (
	KRemotingPath = "remoting"
)

func CRIB_PhOS_Remoting(cmdOpt CmdOptions, buildConf BuildConfigs, logger *log.Logger) {
	if cmdOpt.DoBuild {
		// TODO(zhuobin): we need to install NCCL version according to CUDA version
		utils.CheckAndInstallMultiPackagesViaOsPkgManager([]string{
			"libnccl2=2.26.5-1+cuda12.9", "libnccl-dev=2.26.5-1+cuda12.9",
		}, logger)
		utils.CheckAndInstallPackageViaOsPkgManager("clang", logger)
		utils.CheckAndInstallPackageViaOsPkgManager("cmake", logger)
	}

	build_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		{{.CMD_EXPRORT_ENV_VAR__}}
		cd %s/%s
		LIBPOS_PATH=../lib cargo build --features phos --release 				>>{{.LOG_PATH__}} 2>&1
		cd target/release
		cp server {{.LOCAL_BIN_PATH__}}/xpu-server								>>{{.LOG_PATH__}} 2>&1
		cp libclient.so {{.LOCAL_LIB_PATH__}}/libxpuclient.so					>>{{.LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, KRemotingPath,
	)

	install_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		cd %s/%s/target/release											>>{{.LOG_PATH__}} 2>&1
		cp server {{.SYSTEM_BIN_PATH__}}/xpu-server						>>{{.LOG_PATH__}} 2>&1
		cp libclient.so {{.SYSTEM_LIB_PATH__}}/libxpuclient.so			>>{{.LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, KRemotingPath,
	)

	clean_script := fmt.Sprintf(`
		#set -e
		cd %s/%s
		cargo clean 										>>{{.LOG_PATH__}} 2>&1
		# clean local installcation
		rm -rf {{.LOCAL_BIN_PATH__}}/xpu-server 			>>{{.LOG_PATH__}} 2>&1
		rm -rf {{.LOCAL_LIB_PATH__}}/libxpuclient.so 		>>{{.LOG_PATH__}} 2>&1

		# clean system installation
		rm -rf {{.SYSTEM_BIN_PATH__}}/xpu-server 			>>{{.LOG_PATH__}} 2>&1
		rm -rf {{.SYSTEM_LIB_PATH__}}/libxpuclient.so 		>>{{.LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, KRemotingPath,
	)

	unitOpt := UnitOptions{
		Name:          "PhOS-Remoting",
		BuildScript:   build_script,
		RunScript:     "",
		InstallScript: install_script,
		CleanScript:   clean_script,
		DoBuild:       cmdOpt.DoBuild,
		DoRun:         false,
		DoInstall:     cmdOpt.DoInstall,
		DoClean:       cmdOpt.DoClean,
	}
	ExecuteCRIB(cmdOpt, buildConf, unitOpt, logger)
}

func CRIB_PhOS_Core(cmdOpt CmdOptions, buildConf BuildConfigs, logger *log.Logger) {
	build_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		{{.CMD_EXPRORT_ENV_VAR__}}
		cd %s
		rm -rf ./build

		# protobuf generation
		./bin/protoc --proto_path=. --cpp_out=. pos/include/proto/*.proto pos/cuda_impl/proto/*.proto >>{{.LOG_PATH__}} 2>&1

		# build core
		meson build >>{{.LOG_PATH__}} 2>&1
		cd build
		ninja clean >>{{.LOG_PATH__}} 2>&1
		ninja >>{{.LOG_PATH__}} 2>&1
		cp ./libpos.so {{.LOCAL_LIB_PATH__}} >>{{.LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir,
	)

	install_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		cd %s
		cp ./build/libpos.so {{.SYSTEM_LIB_PATH__}} >>{{.LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir,
	)

	clean_script := fmt.Sprintf(`
		#!/bin/bash
		cd %s
		rm -rf build >>{{.LOG_PATH__}} 2>&1
		# clean local installation
		rm -rf {{.LOCAL_LIB_PATH__}}/libpos.so >>{{.LOG_PATH__}} 2>&1
		# clean system installation
		rm -rf {{.SYSTEM_LIB_PATH__}}/libpos.so >>{{.LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir,
	)

	unitOpt := UnitOptions{
		Name:          "PhOS-Core",
		BuildScript:   build_script,
		RunScript:     "",
		InstallScript: install_script,
		CleanScript:   clean_script,
		DoBuild:       cmdOpt.DoBuild,
		DoRun:         false,
		DoInstall:     cmdOpt.DoInstall,
		DoClean:       cmdOpt.DoClean,
	}
	ExecuteCRIB(cmdOpt, buildConf, unitOpt, logger)
}

func CRIB_PhOS_CLI(cmdOpt CmdOptions, buildConf BuildConfigs, logger *log.Logger) {
	build_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		{{.CMD_EXPRORT_ENV_VAR__}}
		cd %s/%s

		# copy common headers
		rm -rf ./pos/include
		mkdir -p ./pos/include
		{{.CMD_COPY_COMMON_HEADER__}}

		rm -rf build
		meson build >>{{.LOG_PATH__}} 2>&1
		cd build
		ninja  >>{{.LOG_PATH__}} 2>&1
		cp ./pos_cli {{.LOCAL_BIN_PATH__}} >>{{.LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, KPhOSCLIPath,
	)

	install_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		cd %s/%s
		cp ./build/pos_cli {{.SYSTEM_BIN_PATH__}} >>{{.LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, KPhOSCLIPath,
	)

	clean_script := fmt.Sprintf(`
		#!/bin/bash
		cd %s/%s
		rm -rf build
		# clean local installation
		rm -rf {{.LOCAL_BIN_PATH__}}/pos_cli
		# clean system installation
		rm -rf {{.SYSTEM_BIN_PATH__}}/pos_cli
		`,
		cmdOpt.RootDir, KPhOSCLIPath,
	)

	unitOpt := UnitOptions{
		Name:          "PhOS-CLI",
		BuildScript:   build_script,
		RunScript:     "",
		InstallScript: install_script,
		CleanScript:   clean_script,
		DoBuild:       cmdOpt.DoBuild,
		DoRun:         false,
		DoInstall:     cmdOpt.DoInstall,
		DoClean:       cmdOpt.DoClean,
	}
	ExecuteCRIB(cmdOpt, buildConf, unitOpt, logger)
}

func CRIB_PhOS_UnitTest(cmdOpt CmdOptions, buildConf BuildConfigs, logger *log.Logger) {
	build_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		{{.CMD_EXPRORT_ENV_VAR__}}
		cd %s/%s

		# copy common headers
		rm -rf ./pos/include
		mkdir -p ./pos/include
		{{.CMD_COPY_COMMON_HEADER__}}

		rm -rf ./build
		meson build >>{{.LOG_PATH__}} 2>&1
		cd build
		ninja clean
		ninja >>{{.LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, kPhOSUnitTestPath,
	)

	run_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		cd %s/%s/build
		# TODO(zhuobin): remove the CUDA_VISIBLE_DEVICES=0
		CUDA_VISIBLE_DEVICES=0 LD_LIBRARY_PATH=../../lib/ ./pos_test >>{{.LOG_PATH__}} 2>&1
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
		Name:          "PhOS-UnitTest",
		BuildScript:   build_script,
		RunScript:     run_script,
		InstallScript: "",
		CleanScript:   clean_script,
		DoBuild:       cmdOpt.DoBuild,
		DoRun:         true,
		DoInstall:     cmdOpt.DoInstall,
		DoClean:       cmdOpt.DoClean,
	}
	ExecuteCRIB(cmdOpt, buildConf, unitOpt, logger)
}
