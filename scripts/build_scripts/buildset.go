package main

import "github.com/charmbracelet/log"

type BuildOptions struct {
	RootDir        string
	WithThirdParty *bool
	Target         *string
	PrintHelp      *bool
	DoCleaning     *bool
	DoInstall      *bool
	DoUnitTest     *bool
}

func (bo *BuildOptions) print(logger *log.Logger) {

}
