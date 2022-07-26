cmake_minimum_required(VERSION 3.15)

project(cpp_experiments CXX)
include(cmake/StandardProjectSettings.cmake)
include(cmake/PreventInSourceBuilds.cmake)

add_library(cpp_experiments_options INTERFACE)
target_compile_options(cpp_experiments_options INTERFACE -fsanitize=address,undefined)
target_link_options(cpp_experiments_options INTERFACE -fsanitize=address,undefined)

# Link this 'library' to use the warnings specified in CompilerWarnings.cmake
add_library(cpp_experiments_warnings INTERFACE)

# standard compiler warnings
include(cmake/CompilerWarnings.cmake)
set_project_warnings(cpp_experiments_warnings)

# allow for static analysis options
include(cmake/StaticAnalyzers.cmake)

option(BUILD_SHARED_LIBS "Enable compilation of shared libraries" OFF)
option(ENABLE_TESTING "Enable Test Builds" ON)

if (ENABLE_TESTING)
    enable_testing()
endif ()

add_subdirectory(src)
