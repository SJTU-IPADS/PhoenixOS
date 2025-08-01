/*
 * Copyright 2025 The PhoenixOS Authors. All rights reserved.
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

package utils

import (
	"errors"
	"fmt"
	"os/exec"
	"time"
	"strings"
	
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
			ClearLastLine()
			isOSPkgMgrUpdate = true
		}
		return fmt.Sprintf("apt-get install -y %s", pkgName)
	default:
		logger.Fatalf("failed to get pkg installation command: unsupported OS type %s", os)
	}

	return ""
}


func GetPkgCheckCmd(pkgName string, logger *log.Logger) string {
	switch os := GetOS(logger); os {
	case "ubuntu":
		return fmt.Sprintf("dpkg -s %s", pkgName)
	default:
		logger.Fatalf("failed to get pkg installation command: unsupported OS type %s", os)
	}

	return ""
}

func GetMultiPkgInstallCmd(pkgNames []string, logger *log.Logger) string {
	switch os := GetOS(logger); os {
	case "ubuntu":
		if !isOSPkgMgrUpdate {
			logger.Infof("updating apt-get...")
			BashCommandGetOutput("apt-get update", true, logger)
			ClearLastLine()
			isOSPkgMgrUpdate = true
		}
		return fmt.Sprintf("apt-get install -y %s", strings.Join(pkgNames, " "))
	default:
		logger.Fatalf("failed to get pkg installation command: unsupported OS type %s", os)
	}

	return ""
}


func GetPkgUnInstallCmd(pkgName string, logger *log.Logger) string {
	switch os := GetOS(logger); os {
	case "ubuntu":
		return fmt.Sprintf("apt-get remove -y %s", pkgName)
	default:
		logger.Fatalf("failed to get pkg uninstallation command: unsupported OS type %s", os)
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

func CheckGppVersion(desiredVersion int, logger *log.Logger) error {
	// anyway, try register the desired version to the system
	register_script := fmt.Sprintf(`
		#!/bin/bash
		update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-%v %v
		`,
		desiredVersion, desiredVersion,
	)
	_, err := BashScriptGetOutput(register_script, true, logger)
	if err != nil {
		return errors.New("no desired g++ version was founded")
	}

	return nil
}

func SwitchGccVersion(desiredVersion int, logger *log.Logger) {
	if err := CheckGppVersion(desiredVersion, logger); err != nil {
		logger.Infof("no g++-%v installed, installing (this might a bit long)...", desiredVersion)
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
		logger.Fatalf("failed to switch g++ to g++-%v: %v", desiredVersion, err)
	}
	logger.Infof("switch g++ version to g++-%v", desiredVersion)
}

type CustormInstallFunc func() error

func CheckAndInstallPackage(command string, pkgName string, custorm_install, post_install CustormInstallFunc, logger *log.Logger) {
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
			logger.Infof("installing %s via custom script...", command)
			if err := custorm_install(); err != nil {
				logger.Fatalf("failed to execute install pkg %s via custom script: %s", command, err)
			}
			if post_install != nil {
				if err := post_install(); err != nil {
					logger.Fatalf("failed to execute post-install for pkg %s via custom script: %s", command, err)
				}
			}
			// NOTE:	we won't check here, we assume the successful execution of customized command represent
			// 			a success installation
			// if err := CheckCommandExists(command, logger); err != nil {
			// 	logger.Fatalf("failed to install pkg %s via custom script: %s", command, err)
			// }
		}
		ClearLastLine()
		logger.Infof("installed %s", command)
	}
}


func CheckPackageViaOsPkgManager(pkgName string, logger *log.Logger) bool {
    if pkgName == "" {
        logger.Fatalf("no package name provided")
    }

    logger.Infof("checking if %s is installed via OS pkg manager...", pkgName)
    checkCmd := GetPkgCheckCmd(pkgName, logger)
    if _, err := BashCommandGetOutput(checkCmd, true, logger); err != nil {
        logger.Infof("%s is NOT installed: %v", pkgName, err)
        return false
    }
    logger.Infof("%s is already installed", pkgName)
    return true
}


func CheckAndInstallPackageViaOsPkgManager(pkgName string, logger *log.Logger) {
	if len(pkgName) == 0 {
		logger.Fatalf("no package name provided")
	}

	logger.Infof("installing %s via OS pkg manager...", pkgName)
	installCmd := GetPkgInstallCmd(pkgName, logger)
	if _, err := BashCommandGetOutput(installCmd, false, logger); err != nil {
		logger.Fatalf("failed to install pkg %s via OS pkg manager: %s", pkgName, err)
	}
	ClearLastLine()
	logger.Infof("installed %s", pkgName)
}


func CheckAndInstallMultiPackagesViaOsPkgManager(pkgNames []string, logger *log.Logger) {
	if len(pkgNames) == 0 {
		logger.Fatalf("no package names provided")
	}

	logger.Infof("installing %s via OS pkg manager...", strings.Join(pkgNames, ", "))
	installCmd := GetMultiPkgInstallCmd(pkgNames, logger)
	if _, err := BashCommandGetOutput(installCmd, false, logger); err != nil {
		logger.Fatalf("failed to install pkgs %s via OS pkg manager: %s", strings.Join(pkgNames, ", "), err)
	}
	ClearLastLine()
	logger.Infof("installed %s", strings.Join(pkgNames, ", "))
}


func UnInstallPackageViaOsPkgManager(pkgName string, logger *log.Logger) {
	if len(pkgName) == 0 {
		logger.Fatalf("no package name provided")
	}

	logger.Infof("uninstalling %s via OS pkg manager...", pkgName)
	uninstallCmd := GetPkgUnInstallCmd(pkgName, logger)
	if _, err := BashCommandGetOutput(uninstallCmd, false, logger); err != nil {
		logger.Fatalf("failed to uninstall pkg %s via OS pkg manager: %s", pkgName, err)
	}
	ClearLastLine()
	logger.Infof("uninstalled %s", pkgName)
}
