## linux ou windows + wsl ubuntu apenas
## por favor não tentem com mingw ou msvc (compiladores do windows)

cmake_minimum_required(VERSION 3.2)
project(Autocomplete)

include(./ncurses.cmake)


include_directories(include
                    ${NCURSES_INCLUDES}/ncurses
                    )

add_executable(ncurses_test
               src/main.cpp
            )

target_link_libraries(ncurses_test ncurses)