## linux or windows + wsl ubuntu only

cmake_minimum_required(VERSION 3.2)
project(ncurses_tests)

include(./ncurses.cmake) #include external project


include_directories(include
                    ${NCURSES_INCLUDES}/ncurses
                    )

add_executable(ncurses_test
               src/main.cpp
            )

target_link_libraries(ncurses_test ncurses)