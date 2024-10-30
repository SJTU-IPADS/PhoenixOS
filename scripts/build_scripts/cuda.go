package main

import (
	"fmt"

	"github.com/PhoenixOS-IPADS/PhOS/scripts/utils"
	"github.com/charmbracelet/log"
)

const (
	// PhOS CUDA path
	kPhOSAutoGenPath     = "autogen"
	KPhOSCudaPatcherPath = "pos/cuda_impl/patcher"
	KRemotingPath        = "remoting/cuda"
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
		Name:          "PhOS-CUDA-KernelPatcher",
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

func CRIB_PhOS_CUDA_Remoting(cmdOpt CmdOptions, buildConf BuildConfigs, logger *log.Logger) {
	build_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		{{.CMD_EXPRORT_ENV_VAR__}}
		export POS_ENABLE=true
		cd %s/%s
		make libtirpc -j 																	>>{{.LOG_PATH__}} 2>&1
		cp ./submodules/libtirpc/install/lib/libtirpc.so {{.LOCAL_LIB_PATH__}}/libtirpc.so	>>{{.LOG_PATH__}} 2>&1
		cd cpu
		make clean 																			>>{{.LOG_PATH__}} 2>&1
		LOG=INFO make cricket-rpc-server cricket-client.so -j 								>>{{.LOG_PATH__}} 2>&1
		cp cricket-rpc-server {{.LOCAL_BIN_PATH__}}/cricket-rpc-server 						>>{{.LOG_PATH__}} 2>&1
		cp cricket-client.so {{.LOCAL_LIB_PATH__}}/cricket-client.so 						>>{{.LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, KRemotingPath,
	)

	install_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		cd %s/%s
		cp ./submodules/libtirpc/install/lib/libtirpc.so {{.SYSTEM_LIB_PATH__}}/libtirpc.so >>{{.LOG_PATH__}} 2>&1
		cd cpu
		cp cricket-rpc-server {{.SYSTEM_BIN_PATH__}}/cricket-rpc-server >>{{.LOG_PATH__}} 2>&1
		cp cricket-client.so {{.SYSTEM_LIB_PATH__}}/cricket-client.so >>{{.LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, KRemotingPath,
	)

	clean_script := fmt.Sprintf(`
		set -e
		cd %s/%s
		make clean 											>>{{.LOG_PATH__}} 2>&1
		cd cpu
		make clean	 										>>{{.LOG_PATH__}} 2>&1
		# clean local installcation
		rm -rf {{.LOCAL_BIN_PATH__}}/cricket-rpc-server 	>>{{.LOG_PATH__}} 2>&1
		rm -rf {{.LOCAL_LIB_PATH__}}/libtirpc.so 			>>{{.LOG_PATH__}} 2>&1
		rm -rf {{.LOCAL_LIB_PATH__}}/cricket-client.so 		>>{{.LOG_PATH__}} 2>&1
		# clean system installation
		rm -rf {{.SYSTEM_BIN_PATH__}}/cricket-rpc-server 	>>{{.LOG_PATH__}} 2>&1
		rm -rf {{.SYSTEM_LIB_PATH__}}/libtirpc.so			>>{{.LOG_PATH__}} 2>&1
		rm -rf {{.SYSTEM_LIB_PATH__}}/cricket-client.so 	>>{{.LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, KRemotingPath,
	)

	unitOpt := UnitOptions{
		Name:          "PhOS-CUDA-Remoting",
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

func CRIB_PhOS_CUDA(cmdOpt CmdOptions, buildConf BuildConfigs, logger *log.Logger) {
    if cmdOpt.DoBuild {
        // ==================== Prepare ====================
        logger.Infof("pre-build check...")
        utils.CheckAndInstallCommand("git", "git", nil, logger)
        utils.CheckAndInstallCommand("gcc", "build-essential", nil, logger)
        utils.CheckAndInstallCommand("g++", "build-essential", nil, logger)
        utils.CheckAndInstallCommand("add-apt-repository", "software-properties-common", nil, logger)
        utils.CheckAndInstallCommand("yes", "yes", nil, logger)
        utils.CheckAndInstallCommand("cmake", "cmake", nil, logger)
        utils.CheckAndInstallCommand("curl", "curl", nil, logger)
        utils.CheckAndInstallCommand("tar", "tar", nil, logger)
        utils.CheckAndInstallCommand("tmux", "tmux", nil, logger)

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
        utils.CheckAndInstallCommand("meson", "", install_meson, logger)

        install_ninja := func() error {
            _, err := utils.BashScriptGetOutput(`
                #!/bin/bash
                set -e
                pip3 install ninja
                `, false, logger,
            )
            return err
        }
        utils.CheckAndInstallCommand("ninja", "", install_ninja, logger)

        build_cargo := func() error {
            _, err := utils.BashScriptGetOutput(`
                #!/bin/bash
                set -e
                if tmux has-session -t cargo_installer 2>/dev/null; then
                    tmux kill-session -t cargo_installer
                fi
                tmux new -s cargo_installer -d
                tmux send -t cargo_installer "curl https://sh.rustup.rs -sSf | sh; exit 0" ENTER
                tmux send-keys -t cargo_installer C-m
                echo '. "$HOME/.cargo/env"' >> $HOME/.bashrc
                `,
                false, logger,
            )
            return err
        }
        utils.CheckAndInstallCommand("cargo", "", build_cargo, logger)
    }
	
	// ==================== CRIB Dependencies ====================
	if cmdOpt.WithThirdParty {
		logger.Infof("building dependencies...")
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
	CRIB_PhOS_CUDA_Remoting(cmdOpt, buildConf, logger)

	// ==================== CRIB UnitTest ====================
	if cmdOpt.WithUnitTest || cmdOpt.DoClean {
		CRIB_PhOS_UnitTest(cmdOpt, buildConf, logger)
	}
}
