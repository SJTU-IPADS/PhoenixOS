package main

import (
	"flag"
	"fmt"
	"os"
	"strings"

	"github.com/PhoenixOS-IPADS/PhOS/scripts/utils"
	"github.com/charmbracelet/log"
)

func printTitle() {
	fmt.Printf("\n>>>>>>>>>> PhOS Build System <<<<<<<<<<\n")
	fmt.Printf("%s\n", utils.PhOSBanner)
}

func printHelp() {
	fmt.Printf("usage: phos_build [-t=<target>] [-u=<enable>] [-j/c/3]\n")
	fmt.Printf("  -t=<target>     specified build target (options: cuda), default to be cuda\n")
	fmt.Printf("  -u=<enable>     run unittest after building to verify correctness (options: true, false), default to be false\n")
	fmt.Printf("  -i              install after successfully building\n")
	fmt.Printf("  -c              clean previously built assets\n")
	fmt.Printf("  -3              involve third-party library\n")
	fmt.Printf("\n")
}

func main() {
	bo := BuildOptions{
		PrintHelp:      flag.Bool("h", false, "Print help message"),
		WithThirdParty: flag.Bool("3", false, "Build/clean with 3rd parties"),
		DoInstall:      flag.Bool("i", false, "Do installation"),
		DoCleaning:     flag.Bool("c", false, "Do cleanning"),
		DoUnitTest:     flag.Bool("u", false, "Do unit-testing after build"),
		Target:         flag.String("t", "cuda", "Specify target platform"),
	}
	flag.Usage = printHelp
	flag.Parse()

	logger := log.New(os.Stdout)

	// >>>>>>>>>>>>>>>>>>>> build routine starts <<<<<<<<<<<<<<<<<<<
	printTitle()
	bo.print(logger)

	if *bo.PrintHelp {
		printHelp()
		os.Exit(0)
	}

	// setup global variables
	rootDir, err := utils.ExecCommandGetOutput("git rev-parse --show-toplevel", false, logger)
	if err != nil {
		logger.Fatalf("failed to obtain root directory")
	}
	bo.RootDir = strings.TrimRight(string(rootDir), "\n")
	logger.Infof("root directory: %s", bo.RootDir)

	if *bo.Target == "cuda" {
		if *bo.DoCleaning {
			CleanTarget_CUDA(bo, logger)
		} else {
			BuildTarget_CUDA(bo, logger)
		}
	} else {
		log.Fatalf("Unsupported target %s", *bo.Target)
	}

	// if len(os.Args) < 2 {
	// 	fmt.Println("请提供要执行的命令和参数")
	// 	return
	// }

	// // 获取命令和参数
	// command := os.Args[1]
	// args := os.Args[2:]

	// // 执行命令
	// cmd := exec.Command(command, args...)
	// output, err := cmd.CombinedOutput() // 获取标准输出和标准错误

	// if err != nil {
	// 	fmt.Printf("执行命令时出错: %s\n", err)
	// 	return
	// }

	// // 输出结果
	// fmt.Println(string(output))
}
