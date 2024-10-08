package utils

import (
	"fmt"
	"os/exec"

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
	output, err := BashCommandGetOutput(fmt.Sprintf("whereis %s", command), false, logger)
	if err == nil && len(output) == 0 {
		err = exec.ErrNotFound
	}
	return err
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
