package utils

import (
	"bufio"
	"io/fs"
	"os"
	"os/exec"
	"strings"

	"github.com/charmbracelet/log"
)

func GetOS(logger *log.Logger) string {
	file, err := os.Open("/etc/os-release")
	if err != nil {
		logger.Fatalf("failed to detect OS version: failed to open /etc/os-release")
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		line := scanner.Text()
		if strings.HasPrefix(line, "ID=") {
			id := strings.TrimPrefix(line, "ID=")
			id = strings.Trim(id, "\"")
			return id
		}
	}

	logger.Fatalf("failed to detect OS version: no information recorded in /etc/os-release")

	return ""
}

func CreateDir(dir string, overwrite bool, perm fs.FileMode, logger *log.Logger) error {
	if _, err := os.Stat(dir); !os.IsNotExist(err) {
		if overwrite {
			if err := os.RemoveAll(dir); err != nil {
				logger.Warnf("failed to remove old directory of %s: %s", dir, err)
				return err
			}
		} else {
			return os.ErrExist
		}
	} else if err != nil {
		logger.Warnf("failed to obtain information of old directory of %s: %s", dir, err)
		return err
	}
	err := os.MkdirAll(dir, perm)
	if err != nil {
		logger.Warnf("failed to create directory of %s with perm %v: %s", dir, perm, err)
		return err
	}

	return nil
}

func ExecCommandGetOutput(command string, ignoreFailed bool, logger *log.Logger) ([]byte, error) {
	args := strings.Fields(command)
	output, err := exec.Command(args[0], args[1:]...).CombinedOutput()
	if err != nil {
		logger.Warnf("failed to execute \"%s\"", command)
	}

	if ignoreFailed {
		return output, nil
	} else {
		return output, err
	}
}

func ExecScriptGetOutput(script string, ignoreFailed bool, logger *log.Logger) ([]byte, error) {
	output, err := exec.Command("bash", "-c", script).CombinedOutput()
	if err != nil {
		logger.Warnf("failed to execute script\n%s\nerr: %s", script, err)
	}

	if ignoreFailed {
		return output, nil
	} else {
		return output, err
	}
}
