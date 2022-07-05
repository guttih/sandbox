cmake_minimum_required(VERSION 3.9)
project(calculate VERSION 1.0.1 DESCRIPTION "calculate is a simple example of calulation library")

option(USE_ADD "Allow usage of add function" ON) # todo:This is just for show, for now

configure_file(${PROJECT_NAME}Config.h.in ${PROJECT_NAME}Config.h)

include(GNUInstallDirs)

# See explenation SHARED: https://stackoverflow.com/questions/17511496/how-to-create-a-shared-library-with-cmake#answer-45843676
# and here STATIC: https://cgold.readthedocs.io/en/latest/tutorials/libraries/static-shared.html
# You should avoid GLOB
# file(GLOB_RECURSE sources
# ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
# add_library(calculate ${sources})
add_library(${PROJECT_NAME} add.cpp
    multiply.cpp
    subtract.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

# You can also set SOVERSION to a major number of VERSION. So libcalculate.so.1 will be a symlink to calculate.so.1.0.0.
set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION 1)

# Declare public API of your library. This API will be installed for the third-party application. It is a good practice to isolate it in your project tree (like placing it include/ directory). Notice that, private headers should not be installed and I strongly suggest to place them with the source files.
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "include/${PROJECT_NAME}.h")

target_include_directories(${PROJECT_NAME} PUBLIC include
    src
    # "${PROJECT_BINARY_DIR}" # add the binary tree to the search path for include files, so that we will find classerConfig.h
)

install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(FILES "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.pc" DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)