cmake_minimum_required(VERSION 3.26)
project(QRAT
    LANGUAGES CXX
    VERSION 0.1
    HOMEPAGE_URL "https://github.com/canhminhdo/QRAT"
    DESCRIPTION "QRAT - A Reachability Analysis Tool for Quantum Programs"
)

# project settings
include(cmake/ProjectSettings.cmake)
# set c++ standard for the project
include(cmake/CompilerOptions.cmake)
# check external dependencies
include(cmake/ExternalDependencies.cmake)
include(cmake/Doxygen.cmake)

add_subdirectory(src)
#add_subdirectory(extern)

# add documentation
option(BUILD_QRAT_DOC "Build documentation for the QRAT project" ON)
if(BUILD_QRAT_DOC)
    add_subdirectory(doc)
endif()

# add test code
option(BUILD_QRAT_TESTS "Build tests for the QRAT project" ON)
if(BUILD_QRAT_TESTS)
    enable_testing()
    include(GoogleTest) # this modules defines functions to automatically discover test cases for Cmake with the use of GoogleTest
    add_subdirectory(test)
endif()