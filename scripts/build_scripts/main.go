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
}
