## linux or windows + wsl ubuntu only

cmake_minimum_required(VERSION 3.2)
project(ncurses_tests)

include(./ncurses.cmake) #include external project


include_directories(include
                    ${NCURSES_INCLUDES}/ #better include ncurses/... so other headers wont have any problem
                    )

add_executable(ncurses_test
               src/main.cpp
            )

add_dependencies(ncurses_test ncurses) #so ncurses will be compiled before everithing is checked
target_link_directories(ncurses_test PUBLIC ${NCURSES_LIBS}) #need this so cmake will look first for compiled libs instead of system's
target_link_libraries(ncurses_test ncursesw)
