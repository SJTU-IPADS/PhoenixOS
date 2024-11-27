/*
 * Copyright 2024 The PhoenixOS Authors. All rights reserved.
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
	"os"

	"github.com/PhoenixOS-IPADS/PhOS/scripts/utils"
	"github.com/charmbracelet/log"
)

const (
	kPhOSAutoGenPath     = "autogen"
	KPhOSCudaPatcherPath = "pos/cuda_impl/patcher"
)

func CRIB_PhOS_CUDA_Autogen(cmdOpt CmdOptions, buildConf BuildConfigs, logger *log.Logger) {
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
		meson build 	>>{{.LOG_PATH__}} 2>&1
		cd build
		ninja clean
		ninja 			>>{{.LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, kPhOSAutoGenPath,
	)

	run_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		cd %s/%s/build
		LD_LIBRARY_PATH=../../lib/ ./pos_autogen -s ../autogen_cuda/supported/%s -d /usr/local/cuda-%s/include -g ../generated >>{{.LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, kPhOSAutoGenPath,
		buildConf.RuntimeTargetVersion,
		buildConf.RuntimeTargetVersion,
	)

	clean_script := fmt.Sprintf(`
		#!/bin/bash
		cd %s/%s
		rm -rf build 		>>{{.LOG_PATH__}} 2>&1
		rm -rf generated 	>>{{.LOG_PATH__}} 2>&1
		rm -rf pos/include 	>>{{.LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, kPhOSAutoGenPath,
	)

	unitOpt := UnitOptions{
		Name:          "PhOS-Autogen",
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

func CRIB_PhOS_CUDA_KernelPatcher(cmdOpt CmdOptions, buildConf BuildConfigs, logger *log.Logger) {
	build_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		{{.CMD_EXPRORT_ENV_VAR__}}
		cd %s/%s
		rm -rf build
		mkdir build && cd build
		cmake .. 														>>{{.LOG_PATH__}} 2>&1
		make -j 														>>{{.LOG_PATH__}} 2>&1
		if [ ! -e "./release/libpatcher.a" ] || [ ! -e "./patcher.h" ]; then
			exit 1
		fi
		cp ./release/libpatcher.a {{.LOCAL_LIB_PATH__}}/libpatcher.a	>>{{.LOG_PATH__}} 2>&1
		cp ./patcher.h {{.LOCAL_INC_PATH__}}/patcher.h 					>>{{.LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, KPhOSCudaPatcherPath,
	)

	clean_script := fmt.Sprintf(`
		#!/bin/bash
		cd %s/%s
		rm -rf build >>{{.LOG_PATH__}} 2>&1
		# remove local installation
		rm -f {{.LOCAL_LIB_PATH__}}/patcher.h >>{{.LOG_PATH__}} 2>&1
		rm -f {{.LOCAL_INC_PATH__}}/libpatcher.a >>{{.LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, KPhOSCudaPatcherPath,
	)

	unitOpt := UnitOptions{
		Name:          "PhOS-CUDA-PtxPatcher",
		BuildScript:   build_script,
		RunScript:     "",
		InstallScript: "", // is it correct that we don't have any system installation?
		CleanScript:   clean_script,
		DoBuild:       cmdOpt.DoBuild,
		DoRun:         false,
		DoInstall:     cmdOpt.DoInstall,
		DoClean:       cmdOpt.DoClean,
	}
	ExecuteCRIB(cmdOpt, buildConf, unitOpt, logger)
}

func CRIB_PhOS_CUDA(cmdOpt CmdOptions, buildConf BuildConfigs, logger *log.Logger) {
    if cmdOpt.DoBuild {
        // ==================== Prepare ====================
        logger.Infof("pre-build check...")
        utils.CheckAndInstallPackage("git", "git", nil, nil, logger)
        utils.CheckAndInstallPackage("gcc", "build-essential", nil, nil, logger)
        utils.CheckAndInstallPackage("g++", "build-essential", nil, nil, logger)
        utils.CheckAndInstallPackage("add-apt-repository", "software-properties-common", nil, nil, logger)
        utils.CheckAndInstallPackage("yes", "yes", nil, nil, logger)
        utils.CheckAndInstallPackage("cmake", "cmake", nil, nil, logger)
        utils.CheckAndInstallPackage("curl", "curl", nil, nil, logger)
        utils.CheckAndInstallPackage("tar", "tar", nil, nil, logger)
        utils.CheckAndInstallPackage("tmux", "tmux", nil, nil, logger)
		utils.CheckAndInstallPackage("pkg-config", "pkg-config", nil, nil, logger)
		utils.CheckAndInstallPackageViaOsPkgManager("libibverbs-dev", logger)

        // we require g++-13 to use C++20 format for auto-generation
        utils.SwitchGccVersion(13, logger)
        utils.SwitchGccVersion(9, logger)

        install_meson := func() error {
            _, err := utils.BashScriptGetOutput(`
                #!/bin/bash
                set -e
                pip3 install meson
                `, false, logger,
            )
            return err
        }
        utils.CheckAndInstallPackage("meson", "", install_meson, nil, logger)

        install_ninja := func() error {
            _, err := utils.BashScriptGetOutput(`
                #!/bin/bash
                set -e
                pip3 install ninja
                `, false, logger,
            )
            return err
        }
        utils.CheckAndInstallPackage("ninja", "", install_ninja, nil, logger)

        install_cargo := func() error {
            _, err := utils.BashScriptGetOutput(`
                #!/bin/bash
                set -e
                if tmux has-session -t cargo_installer 2>/dev/null; then
                    tmux kill-session -t cargo_installer
                fi
                tmux new -s cargo_installer -d
                tmux send -t cargo_installer "curl https://sh.rustup.rs -sSf | sh; exit 0" ENTER
                tmux send-keys -t cargo_installer C-m
                echo '. "$HOME/.cargo/env"' >> /etc/profile
                `,
                false, logger,
            )
            return err
        }
		post_install_cargo := func() error {
			logger.Infof(
				"Please \"source /etc/profile\" to load environment variables for cargo, and then execute \"%s\" to continue [NOT FINISHED YET!]",
				utils.GetThisCommand(),
			)
			os.Exit(0)
			return nil
		}
        utils.CheckAndInstallPackage("cargo", "", install_cargo, post_install_cargo, logger)
    }

	// ==================== CRIB Dependencies ====================
	if cmdOpt.WithThirdParty {
		logger.Infof("building dependencies...")
		CRIB_LibUuid(cmdOpt, buildConf, logger)
		CRIB_Criu(cmdOpt, buildConf, logger)
		CRIB_LibProtobuf(cmdOpt, buildConf, logger)
		CRIB_LibYamlCpp(cmdOpt, buildConf, logger)
		CRIB_LibClang(cmdOpt, buildConf, logger)

		// TODO: just for fast compilation of PhOS, remove later
		CRIB_PhOS_CUDA_KernelPatcher(cmdOpt, buildConf, logger)
	}

	// ==================== CRIB PhOS ====================
	// CRIB_PhOS_CUDA_KernelPatcher(cmdOpt, buildConf, logger)

    // PhOS Autogen System
	if cmdOpt.DoBuild {
        utils.SwitchGccVersion(13, logger)
    }
	CRIB_PhOS_CUDA_Autogen(cmdOpt, buildConf, logger)

    // PhOS Core System
    if cmdOpt.DoBuild {
        utils.SwitchGccVersion(9, logger)
    }
	CRIB_PhOS_Core(cmdOpt, buildConf, logger)

    // PhOS CLI System
    if cmdOpt.DoBuild {
        utils.SwitchGccVersion(13, logger)
    }
	CRIB_PhOS_CLI(cmdOpt, buildConf, logger)

    // PhOS Remoting System
    if cmdOpt.DoBuild {
        utils.SwitchGccVersion(9, logger)
    }
	CRIB_PhOS_Remoting(cmdOpt, buildConf, logger)

	// ==================== CRIB UnitTest ====================
	if cmdOpt.WithUnitTest || cmdOpt.DoClean {
		CRIB_PhOS_UnitTest(cmdOpt, buildConf, logger)
	}
}
