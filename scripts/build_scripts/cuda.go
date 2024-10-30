package main

import (
	"fmt"
	"os"

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
		cmdOpt.RootDir, kPhOSAutoGenPath,
	)

	run_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		cd %s/%s/build
		LD_LIBRARY_PATH=../../lib/ ./pos_autogen -s ../autogen_cuda/supported/%s -d /usr/local/cuda-%s/include -g ../generated >{{.__LOG_PATH__}} 2&>1
		`,
		cmdOpt.RootDir, kPhOSAutoGenPath,
		buildConf.RuntimeTargetVersion,
		buildConf.RuntimeTargetVersion,
	)

	clean_script := fmt.Sprintf(`
		#!/bin/bash
		cd %s/%s
		rm -rf build >{{.__LOG_PATH__}} 2>&1
		rm -rf generated >{{.__LOG_PATH__}} 2>&1
		rm -rf pos/include >{{.__LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, kPhOSAutoGenPath,
	)

	unitOpt := UnitOptions{
		Name:          "PhOS-Autogen",
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

func CRIB_PhOS_CUDA_KernelPatcher(cmdOpt CmdOptions, buildConf BuildConfigs, logger *log.Logger) {
	build_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		{{.__CMD_EXPRORT_ENV_VAR__}}
		cd %s/%s
		rm -rf build
		mkdir build && cd build
		cmake .. >{{.__LOG_PATH__}} 2>&1
		make -j >{{.__LOG_PATH__}} 2>&1
		if [ ! -e "./release/libpatcher.a" ] || [ ! -e "./patcher.h" ]; then
			exit 1
		fi
		cp ./release/libpatcher.a {{.__LOCAL_LIB_PATH__}}/libpatcher.a >{{.__LOG_PATH__}} 2>&1
		cp ./patcher.h {{.__LOCAL_INC_PATH__}}/patcher.h >{{.__LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, KPhOSCudaPatcherPath,
	)

	clean_script := fmt.Sprintf(`
		#!/bin/bash
		cd %s/%s
		rm -rf build >{{.__LOG_PATH__}} 2>&1
		# remove local installation
		rm -f {{.__LOCAL_LIB_PATH__}}/patcher.h >{{.__LOG_PATH__}} 2>&1
		rm -f {{.__LOCAL_INC_PATH__}}/libpatcher.a >{{.__LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, KPhOSCudaPatcherPath,
	)

	unitOpt := UnitOptions{
		Name:          "PhOS-CUDA-KernelPatcher",
		BuildScript:   build_script,
		RunScript:     "",
		InstallScript: "", // is it correct that we don't have any system installation?
		CleanScript:   clean_script,
		DoBuild:       *cmdOpt.DoBuild,
		DoRun:         false,
		DoInstall:     *cmdOpt.DoInstall,
		DoClean:       *cmdOpt.DoClean,
	}
	ExecuteCRIB(cmdOpt, buildConf, unitOpt, logger)
}

func CRIB_PhOS_CUDA_Remoting(cmdOpt CmdOptions, buildConf BuildConfigs, logger *log.Logger) {
	build_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		{{.__CMD_EXPRORT_ENV_VAR__}}
		export POS_ENABLE=true
		cd %s/%s
		make libtirpc -j >{{.__LOG_PATH__}} 2>&1
		cp ./submodules/libtirpc/install/lib/libtirpc.so {{.__LOCAL_LIB_PATH__}}/libtirpc.so >{{.__LOG_PATH__}}
		cd cpu
		make clean >{{.__LOG_PATH__}}
		LOG=INFO make cricket-rpc-server cricket-client.so -j >{{.__LOG_PATH__}}
		cp cricket-rpc-server {{.__LOCAL_BIN_PATH__}}/cricket-rpc-server >{{.__LOG_PATH__}}
		cp cricket-client.so {{.__LOCAL_LIB_PATH__}}/cricket-client.so >{{.__LOG_PATH__}}
		`,
		cmdOpt.RootDir, KRemotingPath,
	)

	install_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		cd %s/%s
		cp ./submodules/libtirpc/install/lib/libtirpc.so {{.__SYSTEM_LIB_PATH__}}/libtirpc.so >{{.__LOG_PATH__}} 2&>1
		cd cpu
		cp cricket-rpc-server {{.__SYSTEM_BIN_PATH__}}/cricket-rpc-server >{{.__LOG_PATH__}} 2&>1
		cp cricket-client.so {{.__SYSTEM_LIB_PATH__}}/cricket-client.so >{{.__LOG_PATH__}} 2&>1
		`,
		cmdOpt.RootDir, KRemotingPath,
	)

	clean_script := fmt.Sprintf(`
		set -e
		cd %s/%s
		make clean >{{.__LOG_PATH__}} 2&>1
		cd cpu
		make clean >{{.__LOG_PATH__}} 2&>1
		# clean local installcation
		rm {{.__LOCAL_BIN_PATH__}}/cricket-rpc-server >{{.__LOG_PATH__}} 2&>1
		rm {{.__LOCAL_LIB_PATH__}}/libtirpc.so >{{.__LOG_PATH__}} 2&>1
		rm {{.__LOCAL_LIB_PATH__}}/cricket-client.so >{{.__LOG_PATH__}} 2&>1
		# clean system installation
		rm {{.__SYSTEM_BIN_PATH__}}/cricket-rpc-server >{{.__LOG_PATH__}} 2&>1
		rm {{.__SYSTEM_LIB_PATH__}}/libtirpc.so >{{.__LOG_PATH__}} 2&>1
		rm {{.__SYSTEM_LIB_PATH__}}/cricket-client.so >{{.__LOG_PATH__}} 2&>1
		`,
		cmdOpt.RootDir, KRemotingPath,
	)

	unitOpt := UnitOptions{
		Name:          "PhOS-CUDA-Remoting",
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

func BuildTarget_CUDA(cmdOpt CmdOptions, buildConf BuildConfigs, logger *log.Logger) {
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
	utils.SwitchGppVersion(13, logger)
	utils.SwitchGppVersion(9, logger)

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

	buildLogPath := fmt.Sprintf("%s/%s", cmdOpt.RootDir, KLogPath)
	if err := utils.CreateDir(buildLogPath, false, 0775, logger); err != nil && !os.IsExist(err) {
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

	// ==================== Build Dependencies ====================
	if *cmdOpt.WithThirdParty {
		logger.Infof("building dependencies...")
		CRIB_LibProtobuf(cmdOpt, buildConf, logger)
		CRIB_LibYamlCpp(cmdOpt, buildConf, logger)
		CRIB_LibClang(cmdOpt, buildConf, logger)

		// TODO: just for fast compilation of PhOS, remove later
		CRIB_PhOS_CUDA_KernelPatcher(cmdOpt, buildConf, logger)

		if *cmdOpt.WithUnitTest {
			CRIB_LibGoogleTest(cmdOpt, buildConf, logger)
		}
	}

	// ==================== Build PhOS ====================
	// buildKernelPatcher(cmdOpt, logger)
	utils.SwitchGppVersion(13, logger)
	CRIB_PhOS_CUDA_Autogen(cmdOpt, buildConf, logger)

	utils.SwitchGppVersion(9, logger)
	CRIB_PhOS_Core(cmdOpt, buildConf, logger)

	utils.SwitchGppVersion(13, logger)
	CRIB_PhOS_CLI(cmdOpt, buildConf, logger)

	utils.SwitchGppVersion(9, logger)
	CRIB_PhOS_CUDA_Remoting(cmdOpt, buildConf, logger)

	// ==================== Build and Run Unit Test ====================
	if *cmdOpt.WithUnitTest {
		CRIB_PhOS_UnitTest(cmdOpt, buildConf, logger)
	}
}

func CleanTarget_CUDA(cmdOpt CmdOptions, buildConf BuildConfigs, logger *log.Logger) {
	// ==================== Clean Dependencies ====================
	if *cmdOpt.WithThirdParty {
		logger.Infof("cleaning dependencies...")
		CRIB_LibProtobuf(cmdOpt, buildConf, logger)
		CRIB_LibYamlCpp(cmdOpt, buildConf, logger)
		CRIB_LibClang(cmdOpt, buildConf, logger)
		CRIB_LibGoogleTest(cmdOpt, buildConf, logger)

		// TODO: just for fast compilation of PhOS, remove later
		CRIB_PhOS_CUDA_KernelPatcher(cmdOpt, buildConf, logger)
	}

	// ==================== Clean PhOS ====================
	// cleanKernelPatcher(cmdOpt, logger)
	CRIB_PhOS_CUDA_Autogen(cmdOpt, buildConf, logger)
	CRIB_PhOS_Core(cmdOpt, buildConf, logger)
	CRIB_PhOS_CLI(cmdOpt, buildConf, logger)

	// ==================== Clean Unit Test ====================
	CRIB_PhOS_UnitTest(cmdOpt, buildConf, logger)
}
