package utils

import (
	"bufio"
	"fmt"
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

func GetThisCommand() string {
	return strings.Join(os.Args, " ")
}

func ClearLastLine() {
	fmt.Print("\033[F\033[K")
}

func CheckContentExists(filePath, content string) (bool, error) {
    file, err := os.Open(filePath)
    if err != nil {
        return false, err
    }
    defer file.Close()

    scanner := bufio.NewScanner(file)
    for scanner.Scan() {
        if strings.TrimSpace(scanner.Text()) == content {
            return true, nil
        }
    }

    if err := scanner.Err(); err != nil {
        return false, err
    }

    return false, nil
}

func CreateDir(dir string, overwrite bool, perm fs.FileMode, logger *log.Logger) error {
	if _, err := os.Stat(dir); err == nil {
		// has directory exists
		if overwrite {
			logger.Warnf("folder %s already exists, overwrite", dir)
			if err := os.RemoveAll(dir); err != nil {
				logger.Warnf("failed to remove old directory of %s: %s", dir, err)
				return err
			}
		} else {
			logger.Warnf("folder %s already exists, but not overwrite", dir)
			return os.ErrExist
		}
	}
	err := os.MkdirAll(dir, perm)
	if err != nil {
		logger.Warnf("failed to create directory of %s with perm %v: %s", dir, perm, err)
		return err
	}

	return nil
}

func BashCommandGetOutput(command string, ignoreFailed bool, logger *log.Logger) ([]byte, error) {
	args := strings.Fields(command)
	output, err := exec.Command(args[0], args[1:]...).CombinedOutput()
	if err != nil {
		if !ignoreFailed {
			logger.Fatalf("failed to execute \"%s\": %s", command, err)
		}
		return output, err
	}
	output = []byte(strings.TrimSpace(string(output)))
	return output, nil
}

func BashScriptGetOutput(script string, ignoreFailed bool, logger *log.Logger) ([]byte, error) {
	output, err := exec.Command("bash", "-c", script).CombinedOutput()
	if err != nil {
		if !ignoreFailed {
			logger.Fatalf("failed to execute script\n%s\nerr: %s", script, err)
		}
		return output, err
	}
	output = []byte(strings.TrimSpace(string(output)))
	return output, nil
}
