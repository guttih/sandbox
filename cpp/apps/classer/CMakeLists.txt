
cmake_minimum_required(VERSION 3.10)

project(classer VERSION 0.1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(USE_MYMATH "Use tutorial provided math implementation" ON)
option(USE_PEOPLE "Allow usage of the people library" ON)
set(VERSION_DISPLAY_NAME "${PROJECT_NAME} hello worlder")

configure_file(${PROJECT_NAME}Config.h.in ${PROJECT_NAME}Config.h)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
if(USE_MYMATH)
    add_subdirectory(MathFunctions)
    list(APPEND EXTRA_LIBS MathFunctions)
endif()

if(USE_PEOPLE)
    # add the People library
    add_subdirectory(People)
    list(APPEND EXTRA_LIBS People)
endif()

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC ${EXTRA_LIBS})

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_BINARY_DIR}
)

# To build and run
#     cd ~/personal/sandbox/build && cmake --build . && ./classer  88
# To install:
#     sudo cmake --install . 
# To uninstall: more here: https://gitlab.kitware.com/cmake/community/-/wikis/FAQ#can-i-do-make-uninstall-with-cmake
#     sudo xargs rm < ../build/install_manifest.txt

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.h"
    DESTINATION include
)

enable_testing()

add_test(NAME Runs COMMAND ${PROJECT_NAME} 25)
# does the usage message work?
add_test(NAME Usage COMMAND ${PROJECT_NAME})
set_tests_properties(Usage
  PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number"
  )

# define a function to simplify adding tests
function(do_test target arg result)
  add_test(NAME Comp${arg} COMMAND ${target} ${arg})
  set_tests_properties(Comp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction(do_test)

# do a bunch of result based tests
do_test(${PROJECT_NAME} 4 "4 is 2")
do_test(${PROJECT_NAME} 9 "9 is 3")
do_test(${PROJECT_NAME} 5 "5 is 2.236")
do_test(${PROJECT_NAME} 7 "7 is 2.645")
do_test(${PROJECT_NAME} 25 "25 is 5")
do_test(${PROJECT_NAME} -25 "-25 is [-nan|nan|0]")
do_test(${PROJECT_NAME} 0.0001 "0.0001 is 0.01")


# CMake help: https://cmake.org/cmake/help/latest/guide/tutorial/

