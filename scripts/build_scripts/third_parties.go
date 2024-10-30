package main

import (
	"fmt"

	"github.com/charmbracelet/log"
)

const (
	KLibClangPath   = "third_party/libclang-static-build"
	KLibYamlCppPath = "third_party/yaml-cpp"
	kProtobufPath   = "third_party/protobuf"
)

func CRIB_LibGoogleTest(cmdOpt CmdOptions, buildConf BuildConfigs, logger *log.Logger) {
	build_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		{{.__CMD_EXPRORT_ENV_VAR__}}
		cd %s/%s
		if [ ! -d "./build" ] || [ ! -e "./build/lib/libgtest.a" ] || [ ! -e "./build/lib/libgtest_main.a" ]; then
			rm -rf build
			mkdir build && cd build
			cmake .. >{{.__LOG_PATH__}} 2>&1
			make -j >{{.__LOG_PATH__}} 2>&1
		fi
		`,
		cmdOpt.RootDir, KGoogleTestPath,
	)

	clean_script := fmt.Sprintf(`
		#!/bin/bash
		cd %s/%s
		rm -rf build >{{.__LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, KGoogleTestPath,
	)

	unitOpt := UnitOptions{
		Name:          "googleTest",
		BuildScript:   build_script,
		RunScript:     "",
		InstallScript: "",
		CleanScript:   clean_script,
		DoBuild:       *cmdOpt.DoBuild,
		DoRun:         false,
		DoInstall:     *cmdOpt.DoInstall,
		DoClean:       *cmdOpt.DoClean,
	}
	ExecuteCRIB(cmdOpt, buildConf, unitOpt, logger)
}

func CRIB_LibProtobuf(cmdOpt CmdOptions, buildConf BuildConfigs, logger *log.Logger) {
	build_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		{{.__CMD_EXPRORT_ENV_VAR__}}
		# build protobuf
		cd %s/%s
		cmake . -DCMAKE_CXX_STANDARD=17 -Dprotobuf_BUILD_SHARED_LIBS=ON -Dprotobuf_BUILD_TESTS=OFF >{{.__LOG_PATH__}} 2>&1
		cmake --build . --config Release -- -j >{{.__LOG_PATH__}} 2>&1
		cp -r ./libproto*.so* {{.__LOCAL_LIB_PATH__}}
		cp -r ./protoc {{.__LOCAL_BIN_PATH__}}
		cp -r ./protoc-3.21.12.0 {{.__LOCAL_BIN_PATH__}}
		`,
		cmdOpt.RootDir, kProtobufPath,
	)

	install_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		cd %s/%s
		cp -r ./libproto*.so* {{.__SYSTEM_LIB_PATH__}} >{{.__LOG_PATH__}} 2>&1
		cp -r ./protoc {{.__SYSTEM_BIN_PATH__}} >{{.__LOG_PATH__}} 2>&1
		cp -r ./protoc-3.21.12.0 {{.__SYSTEM_BIN_PATH__}} >{{.__LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, kProtobufPath,
	)

	clean_script := fmt.Sprintf(`
		#!/bin/bash
		cd %s/%s
		cmake --build . --target clean >{{.__LOG_PATH__}} 2>&1
		# clean local installation
		rm -rf {{.__LOCAL_LIB_PATH__}}/libproto*.so*
		rm -rf {{.__LOCAL_BIN_PATH__}}/protoc
		rm -rf {{.__LOCAL_BIN_PATH__}}/protoc-3.21.12.0
		# clean system installation
		rm -rf {{.__SYSTEM_LIB_PATH__}}/libproto*.so*
		rm -rf {{.__SYSTEM_BIN_PATH__}}/protoc
		rm -rf {{.__SYSTEM_BIN_PATH__}}/protoc-3.21.12.0
		`,
		cmdOpt.RootDir, kProtobufPath,
	)

	unitOpt := UnitOptions{
		Name:          "Protobuf",
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

func CRIB_LibYamlCpp(cmdOpt CmdOptions, buildConf BuildConfigs, logger *log.Logger) {
	build_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		{{.__CMD_EXPRORT_ENV_VAR__}}
		cd %s/%s
		rm -rf build
		mkdir build && cd build
		cmake -DYAML_BUILD_SHARED_LIBS=on .. >{{.__LOG_PATH__}} 2>&1
		make -j >{{.__LOG_PATH__}} 2>&1
		# local installation
		cp ./libyaml-cpp.so {{.__LOCAL_LIB_PATH__}} >{{.__LOG_PATH__}} 2>&1
		cp ./libyaml-cpp.so.0.8 {{.__LOCAL_LIB_PATH__}} >{{.__LOG_PATH__}} 2>&1
		cp ./libyaml-cpp.so.0.8.0 {{.__LOCAL_LIB_PATH__}} >{{.__LOG_PATH__}} 2>&1
		cp -r ../include/yaml-cpp {{.__LOCAL_INC_PATH__}}/yaml-cpp >{{.__LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, KLibYamlCppPath,
	)

	install_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		cd %s/%s
		cp ./libyaml-cpp.so {{.__SYSTEM_LIB_PATH__}} >{{.__LOG_PATH__}} 2>&1
		cp ./libyaml-cpp.so.0.8 {{.__SYSTEM_LIB_PATH__}} >{{.__LOG_PATH__}} 2>&1
		cp ./libyaml-cpp.so.0.8.0 {{.__SYSTEM_LIB_PATH__}} >{{.__LOG_PATH__}} 2>&1
		cp -r ./include {{.__SYSTEM_INC_PATH__}} >{{.__LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, KLibYamlCppPath,
	)

	clean_script := fmt.Sprintf(`
		#!/bin/bash
		cd %s/%s
		rm -rf build >{{.__LOG_PATH__}} 2>&1
		# clean local installation
		rm -rf {{.__LOCAL_LIB_PATH__}}/libyaml-cpp.so >{{.__LOG_PATH__}} 2>&1
		rm -rf {{.__LOCAL_LIB_PATH__}}/libyaml-cpp.so.0.8 >{{.__LOG_PATH__}} 2>&1
		rm -rf {{.__LOCAL_LIB_PATH__}}/libyaml-cpp.so.0.8.0 >{{.__LOG_PATH__}} 2>&1
		rm -rf {{.__LOCAL_INC_PATH__}}/yaml-cpp
		# clean system installation
		rm -rf {{.__SYSTEM_LIB_PATH__}}/libyaml-cpp.so >{{.__LOG_PATH__}} 2>&1
		rm -rf {{.__SYSTEM_LIB_PATH__}}/libyaml-cpp.so.0.8 >{{.__LOG_PATH__}} 2>&1
		rm -rf {{.__SYSTEM_LIB_PATH__}}/libyaml-cpp.so.0.8.0 >{{.__LOG_PATH__}} 2>&1
		rm -rf {{.__SYSTEM_INC_PATH__}}/yaml-cpp
		`,
		cmdOpt.RootDir, KLibYamlCppPath,
	)

	unitOpt := UnitOptions{
		Name:          "LibYamlCpp",
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

func CRIB_LibClang(cmdOpt CmdOptions, buildConf BuildConfigs, logger *log.Logger) {
	build_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		{{.__CMD_EXPRORT_ENV_VAR__}}
		cd %s/%s
		if [ ! -d "./build" ]; then
			mkdir build && cd build
			cmake .. -DCMAKE_INSTALL_PREFIX=.. >{{.__LOG_PATH__}} 2>&1
			make install -j >{{.__LOG_PATH__}} 2>&1
		fi
		cp ../lib/libclang.so {{.__LOCAL_LIB_PATH__}}/libclang.so >{{.__LOG_PATH__}} 2>&1
		cp ../lib/libclang.so.13 {{.__LOCAL_LIB_PATH__}}/libclang.so.13 >{{.__LOG_PATH__}} 2>&1
		cp ../lib/libclang.so.VERSION {{.__LOCAL_LIB_PATH__}}/libclang.so.VERSION >{{.__LOG_PATH__}} 2>&1
		cp -r ../include/clang-c {{.__LOCAL_INC_PATH__}}/clang-c >{{.__LOG_PATH__}} 2>&1
		`,
		cmdOpt.RootDir, KLibClangPath,
	)

	install_script := fmt.Sprintf(`
		#!/bin/bash
		set -e
		cd %s/%s
		cp ./lib/libclang.so {{.__SYSTEM_LIB_PATH__}}/libclang.so
		cp ./lib/libclang.so.13 {{.__SYSTEM_LIB_PATH__}}/libclang.so.13
		cp ./lib/libclang.so.VERSION {{.__SYSTEM_LIB_PATH__}}/libclang.so.VERSION
		cp -r ./include/clang-c {{.__SYSTEM_INC_PATH__}}/clang-c
		`,
		cmdOpt.RootDir, KLibClangPath,
	)

	clean_script := fmt.Sprintf(`
		#!/bin/bash
		cd %s/%s
		rm -rf build
		rm -rf include
		rm -rf lib
		rm -rf share
		# clean local installation
		rm -f {{.__LOCAL_LIB_PATH__}}/libclang.so
		rm -f {{.__LOCAL_LIB_PATH__}}/libclang.so.13
		rm -f {{.__LOCAL_LIB_PATH__}}/libclang.so.VERSION
		rm -rf {{.__LOCAL_INC_PATH__}}/clang-c
		# clean system installation
		rm -f {{.__SYSTEM_LIB_PATH__}}/libclang.so
		rm -f {{.__SYSTEM_LIB_PATH__}}/libclang.so.13
		rm -f {{.__SYSTEM_LIB_PATH__}}/libclang.so.VERSION
		rm -rf {{.__SYSTEM_INC_PATH__}}/clang-c
		`,
		cmdOpt.RootDir, KLibClangPath,
	)

	unitOpt := UnitOptions{
		Name:          "LibClang",
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
