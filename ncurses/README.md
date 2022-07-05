## Tested in ubuntu/mint, windows wsl+ubuntu ##

This is just a simple example of how to use ncurses with c++ and cmake
to build this project you will need cmake and a c++ compiler, after that
just do the following commands on the terminal, in the folder this README is located:

1. `mkdir build`
2. `cmake ..`
3. `cmake --build .`
4. Executable name is ncurses_test, just run it and have fun

## Spaces are bad ;<

Since ncurses is build with autotools you cant have spaces on the folder that contains the project.
If you use spaces on the folder configuring ncurses will cause the following error:

`configure: error: cannot find install-sh or install.sh <folders with spaces>` 

Which means you are using spaces in some of the folders, just move them from `<folders with spaces>` to `<folders_with_underscores>` or remove the spaces if you like/can.

## Notes about replit

Since ncurses is built along with this project, replit doesn't have enough CPU
to properly handle the build process, so it could take a anoying long time to build. 
There, maybe, we could just install the pre built binaries since it's a linux platform.
  
