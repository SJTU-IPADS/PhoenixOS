package utils

import (
	"errors"
	"fmt"
	"os/exec"
	"regexp"
	"strconv"
	"strings"
	"time"

	"github.com/charmbracelet/log"
)

var (
	isOSPkgMgrUpdate bool
)

func GetPkgInstallCmd(pkgName string, logger *log.Logger) string {
	switch os := GetOS(logger); os {
	case "ubuntu":
		if !isOSPkgMgrUpdate {
			logger.Infof("updating apt-get...")
			BashCommandGetOutput("apt-get update", true, logger)
			isOSPkgMgrUpdate = true
		}
		return fmt.Sprintf("apt-get install -y %s", pkgName)
	default:
		logger.Fatalf("failed to get pkg installation command: unsupported OS type %s", os)
	}

	return ""
}

func CheckCommandExists(command string, logger *log.Logger) error {
	// output, err := BashCommandGetOutput(fmt.Sprintf("whereis %s", command), false, logger)
	_, err := exec.LookPath(command)
	if err != nil {
		err = exec.ErrNotFound
	}
	return err
}

func CheckGppVersion(desiredVersion int, logger *log.Logger) (int, error) {
	versionOutput, err := exec.Command("g++", "--version").Output()
	if err != nil {
		logger.Fatalf("failed to obtain g++ version: %s", err)
	}

	re := regexp.MustCompile(`\d+\.\d+`)
	match := re.FindString(string(versionOutput))
	if match == "" {
		logger.Fatalf("failed to extract g++ version")
	}

	majorVersion, err := strconv.Atoi(strings.Split(match, ".")[0])
	if err != nil {
		logger.Fatalf("failed to major g++ version")
	}

	if majorVersion < desiredVersion {
		// try to switch to higher version
		switch_script := fmt.Sprintf(`
				#!/bin/bash
				update-alternatives --set g++ /usr/bin/g++-%v
			`,
			desiredVersion,
		)
		_, err := BashScriptGetOutput(switch_script, true, logger)
		if err != nil {
			return majorVersion, errors.New("no desired g++ version was founded")
		} else {
			// switch back
			switch_script = fmt.Sprintf(`
					#!/bin/bash
					update-alternatives --set g++ /usr/bin/g++-%v
				`,
				majorVersion,
			)
			_, err := BashScriptGetOutput(switch_script, true, logger)
			if err != nil {
				logger.Fatalf(
					"failed to switch back to old g++ version after finishing checking: old(%v), desired(%v)",
					majorVersion, desiredVersion,
				)
			}
			return desiredVersion, nil
		}

	}

	return majorVersion, nil
}

func SwitchGppVersion(desiredVersion int, logger *log.Logger) {
	if _, err := CheckGppVersion(desiredVersion, logger); err != nil {
		logger.Infof("no g++-%v installed, installing...", desiredVersion)
		install_script := fmt.Sprintf(`
				#!/bin/bash
				add-apt-repository -y ppa:ubuntu-toolchain-r/test
				apt-get update
				apt install -y g++-%v
				update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-%v %v
			`,
			desiredVersion, desiredVersion, desiredVersion,
		)
		start := time.Now()
		_, err := BashScriptGetOutput(install_script, true, logger)
		elapsed := time.Since(start)
		if err != nil {
			logger.Fatalf("failed to install g++-%v: %v", 10, err)
		}
		ClearLastLine()
		logger.Infof("no g++-%v installed, installed [%.2fs]", desiredVersion, elapsed.Seconds())
	}

	switch_script := fmt.Sprintf(`
			#!/bin/bash
			update-alternatives --set g++ /usr/bin/g++-%v
		`,
		desiredVersion,
	)
	_, err := BashScriptGetOutput(switch_script, true, logger)
	if err != nil {
		logger.Fatalf("failed to switch g++ to g++-%v: %v", switch_script, err)
	}
	logger.Infof("switch g++ version to g++-%v", desiredVersion)
}

type CustormInstallFunc func() error

func CheckAndInstallCommand(command string, pkgName string, custorm_install CustormInstallFunc, logger *log.Logger) {
	err := CheckCommandExists(command, logger)
	if err != nil {
		if len(pkgName) == 0 && custorm_install == nil {
			logger.Fatalf("%s is not installed, yet no installation method provided", command)
		} else if len(pkgName) > 0 {
			logger.Infof("installing %s via OS pkg manager...", command)
			installCmd := GetPkgInstallCmd(pkgName, logger)
			if _, err := BashCommandGetOutput(installCmd, false, logger); err != nil {
				logger.Fatalf("failed to install pkg %s via OS pkg manager: %s", command, err)
			}
			if err := CheckCommandExists(command, logger); err != nil {
				logger.Fatalf("failed to install pkg %s via OS pkg manager: %s", command, err)
			}
		} else if custorm_install != nil {
			logger.Infof("installing %s via custom command...", command)
			if err := custorm_install(); err != nil {
				logger.Fatalf("failed to execute install pkg %s via custom script: %s", command, err)
			}
			if err := CheckCommandExists(command, logger); err != nil {
				logger.Fatalf("failed to install pkg %s via custom script: %s", command, err)
			}
		}
		logger.Infof("installed %s", command)
	}
}
