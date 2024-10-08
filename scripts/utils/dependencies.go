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
			ExecCommandGetOutput("apt-get update", true, logger)
			isOSPkgMgrUpdate = true
		}
		return fmt.Sprintf("apt-get install %s", pkgName)
	default:
		logger.Fatalf("failed to get pkg installation command: unsupported OS type %s", os)
	}

	return ""
}

func CheckCommandExists(command string, pkgName string, custorm_install string, logger *log.Logger) {
	_, err := exec.LookPath(command)
	if err != nil {
		if len(pkgName) > 0 {
			logger.Fatalf("%s not installed, please install by \"%s\"", command, GetPkgInstallCmd(pkgName, logger))
		}

		if len(custorm_install) > 0 {
			logger.Fatalf("%s not installed, please install by:\n%s", command, custorm_install)
		}

		logger.Fatalf("%s not installed", command)
	}
}

type CustormInstallFunc func() error

func CheckAndInstallCommand(command string, pkgName string, custorm_install CustormInstallFunc, logger *log.Logger) {
	_, err := exec.LookPath(command)
	if err != nil {
		if len(pkgName) == 0 && custorm_install == nil {
			logger.Fatalf("%s is not installed, yet no installation method provided", command)
		} else if len(pkgName) > 0 {
			logger.Infof("installing %s via OS pkg manager...", pkgName)
			installCmd := GetPkgInstallCmd(pkgName, logger)
			if _, err := ExecCommandGetOutput(installCmd, false, logger); err != nil {
				logger.Fatalf("failed to install pkg %s via OS pkg manager: %s", pkgName, err)
			}
			if _, err := exec.LookPath(command); err != nil {
				logger.Fatalf("failed to install pkg %s via OS pkg manager: %s", pkgName, err)
			}
		} else if custorm_install != nil {
			logger.Infof("installing %s via OS pkg manager...", pkgName)
			if err := custorm_install(); err != nil {
				logger.Fatalf("failed to execute install pkg %s via custom script: %s", pkgName, err)
			}
			if _, err := exec.LookPath(command); err != nil {
				logger.Fatalf("failed to install pkg %s via custom script: %s", pkgName, err)
			}
		}
		logger.Infof("installed %s", pkgName)
	}
}
