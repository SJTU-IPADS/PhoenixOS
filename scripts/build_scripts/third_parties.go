package main

import (
	"fmt"

	"github.com/PhoenixOS-IPADS/PhOS/scripts/utils"
	"github.com/charmbracelet/log"
)

const (
	KUuidPath 		= "third_party/util-linux"
	KCriuPath 		= "third_party/criu"
	KGoogleTestPath = "third_party/googletest"
	KLibClangPath   = "third_party/libclang-static-build"
	KLibYamlCppPath = "third_party/yaml-cpp"
	kProtobufPath   = "third_party/protobuf"
)

func CRIB_LibUuid(cmdOpt CmdOptions, buildConf BuildConfigs, logger *log.Logger) {
	if cmdOpt.DoBuild {
		utils.CheckAndInstallPackage("autopoint", "autopoint", nil, nil, logger)
		utils.CheckAndInstallPackage("autoconf", "autoconf", nil, nil, logger)
		utils.CheckAndInstallPackage("flex", "flex", nil, nil, logger)
		utils.CheckAndInstallPackage("bison", "bison", nil, nil, logger)
		utils.CheckAndInstallPackage("automake", "automake", nil, nil, logger)
		utils.CheckAndInstallPackageViaOsPkgManager("libtool-bin", logger)
	}

	// see following guidance:
	// 1. https://github.com/util-linux/util-linux/blob/master/Documentation/howto-compilation.txt
	// 2. https://github.com/util-linux/util-linux/issues/1372#issuecomment-911713740
	build_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		{{.CMD_EXPRORT_ENV_VAR__}}
		cd %s/%s
		./autogen.sh 														>>{{.LOG_PATH__}} 2>&1
		./configure --disable-all-programs --enable-libuuid --disable-nls	>>{{.LOG_PATH__}} 2>&1
		make -j																>>{{.LOG_PATH__}} 2>&1
		cp ./.libs/libuuid.so {{.LOCAL_LIB_PATH__}}/libuuid.so 				>>{{.LOG_PATH__}} 2>&1
		cp ./.libs/libuuid.so.1 {{.LOCAL_LIB_PATH__}}/libuuid.so.1 			>>{{.LOG_PATH__}} 2>&1
		cp ./.libs/libuuid.so.1.3.0 {{.LOCAL_LIB_PATH__}}/libuuid.so.1.3.0 	>>{{.LOG_PATH__}} 2>&1
		cp ./libuuid/src/uuid.h {{.LOCAL_INC_PATH__}}/uuid.h 				>>{{.LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, KUuidPath,
	)

	clean_script := fmt.Sprintf(`
		#!/bin/bash
		cd %s/%s
		make clean										>>{{.LOG_PATH__}} 2>&1
		# remove local installation
		rm -rf {{.LOCAL_LIB_PATH__}}/libuuid.so 		>>{{.LOG_PATH__}} 2>&1
		rm -rf {{.LOCAL_LIB_PATH__}}/libuuid.so.1		>>{{.LOG_PATH__}} 2>&1
		rm -rf {{.LOCAL_LIB_PATH__}}/libuuid.so.1.3.0	>>{{.LOG_PATH__}} 2>&1
		rm -rf {{.LOCAL_INC_PATH__}}/uuid.h				>>{{.LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, KUuidPath,
	)

	unitOpt := UnitOptions{
		Name:          "libuuid",
		BuildScript:   build_script,
		RunScript:     "",
		InstallScript: "",
		CleanScript:   clean_script,
		DoBuild:       cmdOpt.DoBuild,
		DoRun:         false,
		DoInstall:     cmdOpt.DoInstall,
		DoClean:       cmdOpt.DoClean,
	}
	ExecuteCRIB(cmdOpt, buildConf, unitOpt, logger)
}

func CRIB_Criu(cmdOpt CmdOptions, buildConf BuildConfigs, logger *log.Logger) {
	if cmdOpt.DoBuild {
		// see https://criu.org/Installation
		utils.CheckAndInstallPackageViaOsPkgManager(
			"libprotobuf-dev libprotobuf-c-dev protobuf-c-compiler " +
			"protobuf-compiler python3-protobuf libnet1-dev libcap-dev " +
			"libnl-3-dev libnl-genl-3-dev asciidoctor",
		logger)
	}

	build_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		{{.CMD_EXPRORT_ENV_VAR__}}
		cd %s/%s
		make clean
		make -j										>>{{.LOG_PATH__}} 2>&1
		cp ./criu/criu {{.LOCAL_BIN_PATH__}}/criu	>>{{.LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, KCriuPath,
	)

	install_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		cd %s/%s
		git config --global --add safe.directory /root/third_party/criu	>>{{.LOG_PATH__}} 2>&1
		make install													>>{{.LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, KCriuPath,
	)

	clean_script := fmt.Sprintf(`
		#!/bin/bash
		cd %s/%s
		make uninstall								>>{{.LOG_PATH__}} 2>&1
		# remove local installation
		rm -rf {{.LOCAL_BIN_PATH__}}/criu 			>>{{.LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, KCriuPath,
	)

	unitOpt := UnitOptions{
		Name:          "CRIU",
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

func CRIB_LibGoogleTest(cmdOpt CmdOptions, buildConf BuildConfigs, logger *log.Logger) {
	build_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		{{.CMD_EXPRORT_ENV_VAR__}}
		cd %s/%s
		if [ ! -d "./build" ] || [ ! -e "./build/lib/libgtest.a" ] || [ ! -e "./build/lib/libgtest_main.a" ]; then
			rm -rf build
			mkdir build && cd build
			cmake .. 	>>{{.LOG_PATH__}} 2>&1
			make -j 	>>{{.LOG_PATH__}} 2>&1
		fi
		`,
		cmdOpt.RootDir, KGoogleTestPath,
	)

	clean_script := fmt.Sprintf(`
		#!/bin/bash
		cd %s/%s
		rm -rf build 	>>{{.LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, KGoogleTestPath,
	)

	unitOpt := UnitOptions{
		Name:          "googleTest",
		BuildScript:   build_script,
		RunScript:     "",
		InstallScript: "",
		CleanScript:   clean_script,
		DoBuild:       cmdOpt.DoBuild,
		DoRun:         false,
		DoInstall:     cmdOpt.DoInstall,
		DoClean:       cmdOpt.DoClean,
	}
	ExecuteCRIB(cmdOpt, buildConf, unitOpt, logger)
}

func CRIB_LibProtobuf(cmdOpt CmdOptions, buildConf BuildConfigs, logger *log.Logger) {
	build_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		{{.CMD_EXPRORT_ENV_VAR__}}
		# build protobuf
		cd %s/%s
		cmake . -DCMAKE_CXX_STANDARD=17 -Dprotobuf_BUILD_SHARED_LIBS=ON -Dprotobuf_BUILD_TESTS=OFF >>{{.LOG_PATH__}} 2>&1
		cmake --build . --config Release -- -j 			>>{{.LOG_PATH__}} 2>&1
		cp -r ./libproto*.so* {{.LOCAL_LIB_PATH__}} 	>>{{.LOG_PATH__}} 2>&1
		cp -r ./protoc {{.LOCAL_BIN_PATH__}} 			>>{{.LOG_PATH__}} 2>&1
		cp -r ./protoc-3.21.12.0 {{.LOCAL_BIN_PATH__}} 	>>{{.LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, kProtobufPath,
	)

	install_script := fmt.Sprintf(`
		#!/bin/bash
		set -e

		cd %s/%s
		cp -r ./libproto*.so* {{.SYSTEM_LIB_PATH__}} 	>>{{.LOG_PATH__}} 2>&1
		cp -r ./protoc {{.SYSTEM_BIN_PATH__}} 			>>{{.LOG_PATH__}} 2>&1
		cp -r ./protoc-3.21.12.0 {{.SYSTEM_BIN_PATH__}}	>>{{.LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, kProtobufPath,
	)

	clean_script := fmt.Sprintf(`
		#!/bin/bash
		cd %s/%s
		cmake --build . --target clean 					>>{{.LOG_PATH__}} 2>&1
		# clean local installation
		rm -rf {{.LOCAL_LIB_PATH__}}/libproto*.so*		>>{{.LOG_PATH__}} 2>&1
		rm -rf {{.LOCAL_BIN_PATH__}}/protoc 			>>{{.LOG_PATH__}} 2>&1
		rm -rf {{.LOCAL_BIN_PATH__}}/protoc-3.21.12.0 	>>{{.LOG_PATH__}} 2>&1

		# we don't clean system installation, as it might corrupted CRIU's
		# environment, so the clean is not comprehensive here :(
		`,
		cmdOpt.RootDir, kProtobufPath,
	)

	unitOpt := UnitOptions{
		Name:          "Protobuf",
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

func CRIB_LibYamlCpp(cmdOpt CmdOptions, buildConf BuildConfigs, logger *log.Logger) {
	build_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		{{.CMD_EXPRORT_ENV_VAR__}}
		cd %s/%s
		rm -rf build
		mkdir build && cd build
		cmake -DYAML_BUILD_SHARED_LIBS=on .. 						>>{{.LOG_PATH__}} 2>&1
		make -j 													>>{{.LOG_PATH__}} 2>&1
		# local installation
		cp ./libyaml-cpp.so {{.LOCAL_LIB_PATH__}} 					>>{{.LOG_PATH__}} 2>&1
		cp ./libyaml-cpp.so.0.8 {{.LOCAL_LIB_PATH__}} 				>>{{.LOG_PATH__}} 2>&1
		cp ./libyaml-cpp.so.0.8.0 {{.LOCAL_LIB_PATH__}} 			>>{{.LOG_PATH__}} 2>&1
		cp -r ../include/yaml-cpp {{.LOCAL_INC_PATH__}}/yaml-cpp	>>{{.LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, KLibYamlCppPath,
	)

	install_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		cd %s/%s
		cp ./build/libyaml-cpp.so {{.SYSTEM_LIB_PATH__}} 			>>{{.LOG_PATH__}} 2>&1
		cp ./build/libyaml-cpp.so.0.8 {{.SYSTEM_LIB_PATH__}} 		>>{{.LOG_PATH__}} 2>&1
		cp ./build/libyaml-cpp.so.0.8.0 {{.SYSTEM_LIB_PATH__}} 	>>{{.LOG_PATH__}} 2>&1
		cp -r ./include {{.SYSTEM_INC_PATH__}} 				>>{{.LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, KLibYamlCppPath,
	)

	clean_script := fmt.Sprintf(`
		#!/bin/bash
		cd %s/%s
		rm -rf build 										>>{{.LOG_PATH__}} 2>&1
		# clean local installation
		rm -rf {{.LOCAL_LIB_PATH__}}/libyaml-cpp.so 		>>{{.LOG_PATH__}} 2>&1
		rm -rf {{.LOCAL_LIB_PATH__}}/libyaml-cpp.so.0.8 	>>{{.LOG_PATH__}} 2>&1
		rm -rf {{.LOCAL_LIB_PATH__}}/libyaml-cpp.so.0.8.0 	>>{{.LOG_PATH__}} 2>&1
		rm -rf {{.LOCAL_INC_PATH__}}/yaml-cpp
		# clean system installation
		rm -rf {{.SYSTEM_LIB_PATH__}}/libyaml-cpp.so 		>>{{.LOG_PATH__}} 2>&1
		rm -rf {{.SYSTEM_LIB_PATH__}}/libyaml-cpp.so.0.8 	>>{{.LOG_PATH__}} 2>&1
		rm -rf {{.SYSTEM_LIB_PATH__}}/libyaml-cpp.so.0.8.0 	>>{{.LOG_PATH__}} 2>&1
		rm -rf {{.SYSTEM_INC_PATH__}}/yaml-cpp
		`,
		cmdOpt.RootDir, KLibYamlCppPath,
	)

	unitOpt := UnitOptions{
		Name:          "LibYamlCpp",
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

func CRIB_LibClang(cmdOpt CmdOptions, buildConf BuildConfigs, logger *log.Logger) {
	build_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		{{.CMD_EXPRORT_ENV_VAR__}}
		cd %s/%s
		if [ ! -d "./build" ]; then
			mkdir build && cd build
			cmake .. -DCMAKE_INSTALL_PREFIX=.. 									>>{{.LOG_PATH__}} 2>&1
			make install -j 													>>{{.LOG_PATH__}} 2>&1
		fi
		cp ../lib/libclang.so {{.LOCAL_LIB_PATH__}}/libclang.so 				>>{{.LOG_PATH__}} 2>&1
		cp ../lib/libclang.so.13 {{.LOCAL_LIB_PATH__}}/libclang.so.13 			>>{{.LOG_PATH__}} 2>&1
		cp ../lib/libclang.so.VERSION {{.LOCAL_LIB_PATH__}}/libclang.so.VERSION >>{{.LOG_PATH__}} 2>&1
		cp -r ../include/clang-c {{.LOCAL_INC_PATH__}}/clang-c 					>>{{.LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, KLibClangPath,
	)

	install_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		cd %s/%s
		cp ./lib/libclang.so {{.SYSTEM_LIB_PATH__}}/libclang.so 				>>{{.LOG_PATH__}} 2>&1
		cp ./lib/libclang.so.13 {{.SYSTEM_LIB_PATH__}}/libclang.so.13 			>>{{.LOG_PATH__}} 2>&1
		cp ./lib/libclang.so.VERSION {{.SYSTEM_LIB_PATH__}}/libclang.so.VERSION >>{{.LOG_PATH__}} 2>&1
		cp -r ./include/clang-c {{.SYSTEM_INC_PATH__}}/clang-c 					>>{{.LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, KLibClangPath,
	)

	clean_script := fmt.Sprintf(`
		#!/bin/bash
		cd %s/%s
		rm -rf build										>>{{.LOG_PATH__}} 2>&1
		rm -rf include										>>{{.LOG_PATH__}} 2>&1
		rm -rf lib											>>{{.LOG_PATH__}} 2>&1
		rm -rf share										>>{{.LOG_PATH__}} 2>&1
		# clean local installation
		rm -f {{.LOCAL_LIB_PATH__}}/libclang.so				>>{{.LOG_PATH__}} 2>&1
		rm -f {{.LOCAL_LIB_PATH__}}/libclang.so.13			>>{{.LOG_PATH__}} 2>&1
		rm -f {{.LOCAL_LIB_PATH__}}/libclang.so.VERSION		>>{{.LOG_PATH__}} 2>&1
		rm -rf {{.LOCAL_INC_PATH__}}/clang-c				>>{{.LOG_PATH__}} 2>&1
		# clean system installation
		rm -f {{.SYSTEM_LIB_PATH__}}/libclang.so			>>{{.LOG_PATH__}} 2>&1
		rm -f {{.SYSTEM_LIB_PATH__}}/libclang.so.13			>>{{.LOG_PATH__}} 2>&1
		rm -f {{.SYSTEM_LIB_PATH__}}/libclang.so.VERSION	>>{{.LOG_PATH__}} 2>&1
		rm -rf {{.SYSTEM_INC_PATH__}}/clang-c				>>{{.LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, KLibClangPath,
	)

	unitOpt := UnitOptions{
		Name:          "LibClang",
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
