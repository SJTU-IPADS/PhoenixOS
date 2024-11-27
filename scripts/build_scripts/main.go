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
	"flag"
	"fmt"
	"os"

	"github.com/PhoenixOS-IPADS/PhOS/scripts/utils"
	"github.com/charmbracelet/log"
	"gopkg.in/yaml.v2"
)

func printTitle() {
	fmt.Printf("\n>>>>>>>>>> PhOS Build System <<<<<<<<<<\n")
	fmt.Printf("%s\n", utils.PhOSBanner)
}

func printHelp() {
	fmt.Printf("usage: phos_build [-t=<target>] [-u=<enable>] [-j/c/3]\n")
	fmt.Printf("  -t=<target>	specified build target (options: cuda), default to be cuda\n")
	fmt.Printf("  -u     		run unittest after building to verify correctness (options: true, false), default to be false\n")
	fmt.Printf("  -i   			install after successfully building\n")
	fmt.Printf("  -c   			clean previously built assets\n")
	fmt.Printf("  -3          	involve third-party library\n")
	fmt.Printf("\n")
}

func main() {
	logger := log.New(os.Stdout)

	var __PrintHelp *bool = flag.Bool("h", false, "Print help message")
	var __WithThirdParty *bool = flag.Bool("3", false, "Build/clean with 3rd parties")
	var __DoInstall *bool = flag.Bool("i", false, "Do installation")
	var __DoClean *bool = flag.Bool("c", false, "Do cleanning")
	var __WithUnitTest *bool = flag.Bool("u", false, "Do unit-testing after build")
	var __Target *string = flag.String("t", "cuda", "Specify target platform")

	flag.Usage = printHelp
	flag.Parse()

	// load command line options
	cmdOpt := CmdOptions{
		PrintHelp:      *__PrintHelp,
		WithThirdParty: *__WithThirdParty,
		DoInstall:      *__DoInstall,
		DoClean:        *__DoClean,
		WithUnitTest:   *__WithUnitTest,
		Target:         *__Target,
	}

	// load build options
	var buildConf BuildConfigs
	builopt_data, err := os.ReadFile("./build_configs.yaml")
	if err != nil {
		log.Warnf("failed to load build options, use default value")
	}
	err = yaml.Unmarshal(builopt_data, &buildConf)
	if err != nil {
		log.Warnf("failed to parse build options from yaml, use default value")
	}
	buildConf.init(logger)

	// >>>>>>>>>>>>>>>>>>>> build routine starts <<<<<<<<<<<<<<<<<<<
	// setup global variables
	cmdOpt.RootDir = buildConf.PlatformProjectRoot

	printTitle()
	cmdOpt.print(logger)
	buildConf.print(logger)

	if cmdOpt.PrintHelp {
		printHelp()
		os.Exit(0)
	}

	// make sure we won't build/install when clean
	if cmdOpt.DoClean {
		cmdOpt.DoBuild = false
		cmdOpt.DoInstall = false
	} else {
		cmdOpt.DoBuild = true
	}

	CRIB_PhOS(cmdOpt, buildConf, logger)

	if cmdOpt.DoInstall {
		// insert environment variable to /etc/profile file
		ldPreload := "export phos=\"LD_PRELOAD=cricket-client.so\"\n"
		exists, err := utils.CheckContentExists("/etc/profile", ldPreload)
		if err != nil {
			logger.Fatalf("failed to check file content of /etc/profile")
		}
		if(!exists){
			file, err := os.OpenFile("/etc/profile", os.O_APPEND|os.O_WRONLY|os.O_CREATE, 0644)
			if err != nil {
				logger.Fatal("failed to open /etc/profile: %v", err)
			}
			defer file.Close()

			if _, err := file.WriteString(ldPreload); err != nil {
				logger.Fatal("failed to write /etc/profile: %v", err)
			}
		}

		// print prompt
		logger.Infof(
			"\n" +
			"========================================\n" +
			"All system go, PhOS is go for launch :)\n" +
			"========================================\n" +
			"1. Please \"source /etc/profile\" to let PhOS installation take effect\n" + 
			"2. PhOS daemon (phosd) is not running yet, please start it by \"pos_cli --start --target daemon\"\n" +
			"3. To run program with PhOS support, an example looks like \"env $phos python3 train.py \"",
		)
	}
}
