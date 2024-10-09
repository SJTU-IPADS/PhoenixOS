package main

import (
	"fmt"
	"os"

	"github.com/PhoenixOS-IPADS/PhOS/scripts/utils"
	"github.com/charmbracelet/log"
)

const (
	KLibClangPath    = "third_party/libclang-static-build"
	KPhOSPath        = "pos"
	KPhOSCLIPath     = "pos/cli"
	KPhOSPatcherPath = "pos/cuda_impl/patcher"
	KBuildLogPath    = "build_log"
	KBuildLibPath    = "lib"
	KBuildIncPath    = "lib/pos/include"
	KBuildBinPath    = "bin"
	KInstallLibPath  = "/lib/x86_64-linux-gnu"
	KInstallIncPath  = "/usr/local/include"
	KInstallBinPath  = "/usr/local/bin"
)

func buildLibClang(bo BuildOptions, logger *log.Logger) {
	logger.Infof("building libclang...")

	buildLogPath := fmt.Sprintf("%s/%s/%s", bo.RootDir, KBuildLogPath, "build_libclang.log")
	build_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		cd %s/%s
		if [ ! -d "./build" ]; then
			mkdir build && cd build
			cmake .. -DCMAKE_INSTALL_PREFIX=.. >%s 2>&1
			make install -j >%s 2>&1
		fi
		cp ../lib/libclang.so %s
		cp ../lib/libclang.so.13 %s
		cp ../lib/libclang.so.VERSION %s
		cp ../lib/libclang_static.a %s
		cp -r ../include/* %s
		`,
		bo.RootDir, KLibClangPath,
		buildLogPath,
		buildLogPath,
		fmt.Sprintf("%s/%s", bo.RootDir, KBuildLibPath),
		fmt.Sprintf("%s/%s", bo.RootDir, KBuildLibPath),
		fmt.Sprintf("%s/%s", bo.RootDir, KBuildLibPath),
		fmt.Sprintf("%s/%s", bo.RootDir, KBuildLibPath),
		fmt.Sprintf("%s/%s", bo.RootDir, KBuildIncPath),
	)

	install_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		cd %s/%s
		cp ./lib/libclang.so %s/
		cp ./lib/libclang.so.13 %s/
		cp ./lib/libclang.so.VERSION %s/
		cp ./lib/libclang_static.a %s/
		cp -r ./include/clang-c %s/clang-c
		`,
		bo.RootDir, KLibClangPath,
		KInstallLibPath,
		KInstallLibPath,
		KInstallLibPath,
		KInstallLibPath,
		KInstallIncPath,
	)

	_, err := utils.BashScriptGetOutput(build_script, false, logger)
	if err != nil {
		logger.Fatalf("failed to build libclang, please see log at %s", buildLogPath)
	}
	logger.Infof("built libclang")

	if *bo.DoInstall {
		_, err := utils.BashScriptGetOutput(install_script, false, logger)
		if err != nil {
			logger.Fatalf("failed to install libclang, please see log at %s", buildLogPath)
		}
		logger.Infof("installed libclang")
	}
}

func buildKernelPatcher(bo BuildOptions, logger *log.Logger) {
	logger.Infof("building CUDA kernel patcher...")

	buildLogPath := fmt.Sprintf("%s/%s/%s", bo.RootDir, KBuildLogPath, "build_kernel_patcher.log")
	build_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		cd %s/%s
		if [ -d "./build" ]; then
			rm -rf build
		fi
		mkdir build && cd build
		cmake .. >%s 2>&1
		make -j >%s 2>&1
		if [ ! -e "./release/libpatcher.a" ] || [ ! -e "./patcher.h" ]; then
			exit 1
		fi
		cp ./release/libpatcher.a %s/%s
		cp ./patcher.h %s/%s
		`,
		bo.RootDir, KPhOSPatcherPath,
		buildLogPath,
		buildLogPath,
		bo.RootDir, KBuildLibPath,
		bo.RootDir, KBuildIncPath,
	)

	install_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		cd %s/%s
		if [ -e "./release/libpatcher.a" ]; then
			cp ./release/libpatcher.a %s/
		else
			exit 1
		fi
		`,
		bo.RootDir, KLibClangPath,
		KInstallLibPath,
	)

	_, err := utils.BashScriptGetOutput(build_script, false, logger)
	if err != nil {
		logger.Fatalf("failed to build CUDA kernel patcher, please see log at %s", buildLogPath)
	}
	logger.Infof("built CUDA kernel patcher")

	if *bo.DoInstall {
		_, err := utils.BashScriptGetOutput(install_script, false, logger)
		if err != nil {
			logger.Fatalf("failed to install CUDA kernel patcher, please see log at %s", buildLogPath)
		}
		logger.Infof("installed CUDA kernel patcher")
	}
}

func buildPhOSCore(bo BuildOptions, logger *log.Logger) {
	logger.Infof("building PhOS core...")

	buildLogPath := fmt.Sprintf("%s/%s/%s", bo.RootDir, KBuildLogPath, "build_phos_core.log")
	build_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		cd %s
		if [ ! -d "./build" ]; then
			meson build &>%s 2>&1
		fi
		cd build
		ninja clean
		ninja &>%s 2>&1
		cp %s/build/libpos.so %s/%s
		cp %s/build/pos/include/* %s/%s
		`,
		bo.RootDir,
		buildLogPath,
		buildLogPath,
		bo.RootDir, bo.RootDir, KBuildLibPath,
		bo.RootDir, bo.RootDir, KBuildIncPath,
	)

	install_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		cp %s/build/*.so %s
		`,
		bo.RootDir, KInstallLibPath,
	)

	_, err := utils.BashScriptGetOutput(build_script, false, logger)
	if err != nil {
		logger.Fatalf("failed to build PhOS Core for CUDA target, please see log at %s", buildLogPath)
	}
	logger.Infof("built PhOS Core for CUDA target")

	if *bo.DoInstall {
		_, err := utils.BashScriptGetOutput(install_script, false, logger)
		if err != nil {
			logger.Fatalf("failed to install PhOS core, please see log at %s", buildLogPath)
		}
		logger.Infof("installed PhOS core")
	}
}

func buildPhOSCLI(bo BuildOptions, logger *log.Logger) {
	logger.Infof("building PhOS CLI...")

	buildLogPath := fmt.Sprintf("%s/%s/%s", bo.RootDir, KBuildLogPath, "build_phos_cli.log")
	build_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		cd %s/%s
		if [ ! -d "./build" ]; then
			mkdir build
		fi
		cd build && rm -rf ./*
		cmake .. &>%s 2>&1
		make -j  &>%s 2>&1
		cp ./pos-cli %s/%s
		`,
		bo.RootDir, KPhOSCLIPath,
		buildLogPath,
		buildLogPath,
		bo.RootDir, KBuildBinPath,
	)

	install_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		cd %s/%s
		cp ./build/pos-cli %s &>%s
		`,
		bo.RootDir, KPhOSCLIPath,
		KInstallBinPath, buildLogPath,
	)

	_, err := utils.BashScriptGetOutput(build_script, false, logger)
	if err != nil {
		logger.Fatalf("failed to build PhOS CLI: %s", err)
	}
	logger.Infof("built PhOS CLI")

	if *bo.DoInstall {
		_, err := utils.BashScriptGetOutput(install_script, false, logger)
		if err != nil {
			logger.Fatalf("failed to install PhOS CLI, please see log at %s", buildLogPath)
		}
		logger.Infof("installed PhOS CLI")
	}
}

func buildRemoting(bo BuildOptions, logger *log.Logger) {

}

func buildUnitTest(bo BuildOptions, logger *log.Logger) {

}

func BuildTarget_CUDA(bo BuildOptions, logger *log.Logger) {
	// ==================== Prepare ====================
	logger.Infof("pre-build check...")
	utils.CheckAndInstallCommand("git", "git", nil, logger)
	utils.CheckAndInstallCommand("gcc", "build-essential", nil, logger)
	utils.CheckAndInstallCommand("g++", "build-essential", nil, logger)
	utils.CheckAndInstallCommand("yes", "yes", nil, logger)
	utils.CheckAndInstallCommand("cmake", "cmake", nil, logger)
	utils.CheckAndInstallCommand("curl", "curl", nil, logger)
	utils.CheckAndInstallCommand("tar", "tar", nil, logger)
	utils.CheckAndInstallCommand("tmux", "tmux", nil, logger)

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

	buildLogPath := fmt.Sprintf("%s/%s", bo.RootDir, KBuildLogPath)
	if err := utils.CreateDir(buildLogPath, false, 0775, logger); err != nil && !os.IsExist(err) {
		logger.Fatalf("failed to create directory for build logs at %s", buildLogPath)
	}

	libPath := fmt.Sprintf("%s/%s", bo.RootDir, KBuildLibPath)
	if err := utils.CreateDir(libPath, false, 0775, logger); err != nil && !os.IsExist(err) {
		logger.Fatalf("failed to create directory for built lib at %s", libPath)
	}

	includePath := fmt.Sprintf("%s/%s", bo.RootDir, KBuildIncPath)
	if err := utils.CreateDir(includePath, false, 0775, logger); err != nil && !os.IsExist(err) {
		logger.Fatalf("failed to create directory for built headers at %s", includePath)
	}

	binPath := fmt.Sprintf("%s/%s", bo.RootDir, KBuildBinPath)
	if err := utils.CreateDir(binPath, false, 0775, logger); err != nil && !os.IsExist(err) {
		logger.Fatalf("failed to create directory for built binary at %s", binPath)
	}

	// ==================== Build Dependencies ====================
	if *bo.WithThirdParty {
		logger.Infof("building dependencies...")
		buildLibClang(bo, logger)
	}

	// ==================== Build PhOS ====================
	buildKernelPatcher(bo, logger)
	buildPhOSCore(bo, logger)
	buildPhOSCLI(bo, logger)
	buildRemoting(bo, logger)

	if *bo.DoUnitTest {
		buildUnitTest(bo, logger)
	}
}

func cleanCommon(bo BuildOptions, logger *log.Logger) {
	logger.Infof("cleaning common directoroies...")
	clean_script := ""
	if *bo.WithThirdParty {
		clean_script = fmt.Sprintf(`
			#!/bin/bash
			rm -rf %s/%s/*
			rm -rf %s/%s/*
			rm -rf %s/%s/*
			rm -rf %s/%s/*
			`,
			bo.RootDir, KBuildBinPath,
			bo.RootDir, KBuildLibPath,
			bo.RootDir, KBuildLogPath,
			bo.RootDir, KBuildIncPath,
		)
	} else {
		clean_script = fmt.Sprintf(`
			#!/bin/bash
			rm -rf %s/%s/*
			rm -rf %s/%s/libpos.so
			rm -rf %s/%s/libpatcher.a
			rm -rf %s/%s/*.h
			rm -rf %s/%s/*
			`,
			bo.RootDir, KBuildBinPath,
			bo.RootDir, KBuildLibPath,
			bo.RootDir, KBuildLibPath,
			bo.RootDir, KBuildIncPath,
			bo.RootDir, KBuildLogPath,
		)
	}

	_, err := utils.BashScriptGetOutput(clean_script, true, logger)
	if err != nil {
		logger.Warnf("failed to clean common directoroies")
	} else {
		logger.Infof("done")
	}
}

func cleanLibClang(bo BuildOptions, logger *log.Logger) {
	logger.Infof("cleaning libclang...")
	clean_script := fmt.Sprintf(`
		#!/bin/bash
		cd %s/%s
		rm -rf build
		rm -rf include
		rm -rf lib
		rm -rf share
		rm -f %s/libclang.so
		rm -f %s/libclang.so.13
		rm -f %s/libclang.so.VERSION
		rm -f %s/libclang_static.a
		rm -rf %s/clang-c
		`,
		bo.RootDir, KLibClangPath,
		KInstallLibPath,
		KInstallLibPath,
		KInstallLibPath,
		KInstallLibPath,
		KInstallIncPath,
	)
	_, err := utils.BashScriptGetOutput(clean_script, true, logger)
	if err != nil {
		logger.Warnf("failed to clean libclang")
	}
	logger.Infof("done")
}

func cleanKernelPatcher(bo BuildOptions, logger *log.Logger) {
	logger.Infof("cleaning CUDA kernel patcher...")
	clean_script := fmt.Sprintf(`
		#!/bin/bash
		cd %s/%s
		rm -rf build
		rm -f %s/patcher.h
		rm -f %s/libpatcher.a
		`,
		bo.RootDir, KPhOSPatcherPath,
		KInstallIncPath,
		KInstallLibPath,
	)
	_, err := utils.BashScriptGetOutput(clean_script, true, logger)
	if err != nil {
		logger.Warnf("failed to clean libclang")
	}
	logger.Infof("done")
}

func cleanPhOSCore(bo BuildOptions, logger *log.Logger) {
	logger.Infof("cleaning PhOS core...")
	clean_script := fmt.Sprintf(`
		#!/bin/bash
		cd %s
		rm -rf build
		rm -f %s/libpos.so
		`,
		bo.RootDir,
		KInstallLibPath,
	)
	_, err := utils.BashScriptGetOutput(clean_script, true, logger)
	if err != nil {
		logger.Fatalf("failed to clean PhOS core")
	}
	logger.Infof("done")
}

func cleanPhOSCLI(bo BuildOptions, logger *log.Logger) {
	logger.Infof("cleaning PhOS CLI...")
	clean_script := fmt.Sprintf(`
		#!/bin/bash
		cd %s/%s
		rm -rf build
		rm -f %s/pos-cli
		`,
		bo.RootDir, KPhOSCLIPath,
		KInstallBinPath,
	)
	_, err := utils.BashScriptGetOutput(clean_script, true, logger)
	if err != nil {
		logger.Fatalf("failed to clean PhOS CLI")
	}
	logger.Infof("done")
}

func CleanTarget_CUDA(bo BuildOptions, logger *log.Logger) {
	// ==================== Clean Dependencies ====================
	if *bo.WithThirdParty {
		logger.Infof("cleaning dependencies...")
		cleanLibClang(bo, logger)
	}
	cleanCommon(bo, logger)
	cleanKernelPatcher(bo, logger)
	cleanPhOSCore(bo, logger)
	cleanPhOSCLI(bo, logger)
}
