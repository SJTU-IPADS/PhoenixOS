package utils

import (
	"fmt"
	"os/exec"

	"github.com/charmbracelet/log"
)

func GetPkgInstallCmd(pkgName string, logger *log.Logger) string {
	switch os := GetOS(logger); os {
	case "ubuntu":
		return fmt.Sprintf("sudo apt-get install %s", pkgName)
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
