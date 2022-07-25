include(ExternalProject)

set(NCURSES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ncurses-6.3)
set(NCURSES_BIN ${CMAKE_CURRENT_BINARY_DIR}/ncurses)
set(NCURSES_STATIC_LIB ${NCURSES_BIN}/lib/libncursesw.a)
set(NCURSES_LIBS ${NCURSES_BIN}/lib/)
set(NCURSES_INCLUDES ${NCURSES_BIN}/include)

ExternalProject_Add(
    libncurses
    PREFIX ${NCURSES_BIN}
    SOURCE_DIR ${NCURSES_DIR}
    CONFIGURE_COMMAND ${NCURSES_DIR}/configure --prefix=${NCURSES_BIN} --enable-static=yes --disable-shared --enable-widec
    BUILD_COMMAND make
    INSTALL_COMMAND make install
    BUILD_BYPRODUCTS ${NCURSES_STATIC_LIB}
)

add_library(ncurses STATIC IMPORTED GLOBAL)

add_dependencies(ncurses libncurses)
