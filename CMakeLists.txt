cmake_minimum_required(VERSION 3.28)

file(READ "${CMAKE_SOURCE_DIR}/VERSION" _version)
string(STRIP "${_version}" _version)

project(
  Alcia
  VERSION ${_version}
  DESCRIPTION "A text-based RPG with Qt 6"
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(GNUInstallDirs)
include(cmake/Ccache.cmake)
include(cmake/CompilerWarnings.cmake)
include(cmake/CompileOptions.cmake)
include(cmake/Sanitizers.cmake)
include(cmake/Hardening.cmake)
include(cmake/ClangTidy.cmake)
include(cmake/StaticAnalyzers.cmake)
include(cmake/Coverage.cmake)
include(cmake/Doxygen.cmake)
include(cmake/LicenseHeader.cmake)
include(cmake/Iwyu.cmake)
include(cmake/Benchmark.cmake)

option(ALCIA_ENABLE_TESTS "Build tests" ON)
option(ALCIA_ENABLE_BENCHMARKS "Build benchmarks" OFF)
option(ALCIA_ENABLE_COVERAGE "Enable code coverage" OFF)
option(ALCIA_ENABLE_SANITIZERS "Enable sanitizers" OFF)
option(ALCIA_ENABLE_HARDENING "Enable hardening flags" OFF)
option(ALCIA_ENABLE_CLANG_TIDY "Enable clang-tidy" OFF)
option(ALCIA_ENABLE_CPPCHECK "Enable cppcheck" OFF)
option(ALCIA_ENABLE_IWYU "Enable include-what-you-use" OFF)
option(ALCIA_ENABLE_DOXYGEN "Generate Doxygen documentation" OFF)
option(ALCIA_ENABLE_FUZZING "Enable fuzz targets (libFuzzer)" OFF)
option(ALCIA_CHECK_LICENSES "Check/add license headers" OFF)

find_package(Qt6 6.11 REQUIRED COMPONENTS Core Widgets Test)
qt_standard_project_setup()

if(ALCIA_ENABLE_TESTS)
  find_package(GTest REQUIRED)
endif()

if(ALCIA_ENABLE_BENCHMARKS)
  find_package(benchmark REQUIRED)
endif()

if(ALCIA_ENABLE_SANITIZERS)
  alcia_enable_sanitizers()
endif()

if(ALCIA_ENABLE_CLANG_TIDY)
  alcia_enable_clang_tidy()
endif()

if(ALCIA_ENABLE_CPPCHECK)
  alcia_enable_cppcheck()
endif()

if(ALCIA_ENABLE_COVERAGE)
  alcia_enable_coverage()
endif()

if(ALCIA_CHECK_LICENSES)
  alcia_check_license_headers()
endif()

if(CMAKE_EXPORT_COMPILE_COMMANDS)
  execute_process(
    COMMAND ${CMAKE_COMMAND} -E create_symlink "${CMAKE_BINARY_DIR}/compile_commands.json"
            "${CMAKE_SOURCE_DIR}/compile_commands.json")
endif()

add_subdirectory(src)

if(ALCIA_ENABLE_TESTS OR ALCIA_ENABLE_BENCHMARKS)
  enable_testing()
  include(CTest)
  add_subdirectory(tests)
endif()

if(ALCIA_ENABLE_DOXYGEN)
  alcia_setup_doxygen()
endif()

include(cmake/Packaging.cmake)
