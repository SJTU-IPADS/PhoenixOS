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

	// load command line options
	cmdOpt := CmdOptions{
		PrintHelp:      flag.Bool("h", false, "Print help message"),
		WithThirdParty: flag.Bool("3", false, "Build/clean with 3rd parties"),
		DoInstall:      flag.Bool("i", false, "Do installation"),
		DoCleaning:     flag.Bool("c", false, "Do cleanning"),
		DoUnitTest:     flag.Bool("u", false, "Do unit-testing after build"),
		Target:         flag.String("t", "cuda", "Specify target platform"),
	}
	flag.Usage = printHelp
	flag.Parse()

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

	if *cmdOpt.PrintHelp {
		printHelp()
		os.Exit(0)
	}

	if *cmdOpt.Target == "cuda" {
		if *cmdOpt.DoCleaning {
			CleanTarget_CUDA(cmdOpt, logger)
		} else {
			BuildTarget_CUDA(cmdOpt, buildConf, logger)
		}
	} else {
		log.Fatalf("Unsupported target %s", *cmdOpt.Target)
	}
}
