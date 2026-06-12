if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan_provider.cmake")
  find_program(CONAN_CMD conan REQUIRED)

  set(_profile "${CMAKE_SOURCE_DIR}/.conan/profile")

  string(TOLOWER "${CMAKE_BUILD_TYPE}" _build_type_lower)
  if(_build_type_lower STREQUAL "debug")
    set(_conan_build_type "Debug")
  elseif(_build_type_lower STREQUAL "relwithdebinfo")
    set(_conan_build_type "RelWithDebInfo")
  else()
    set(_conan_build_type "Release")
  endif()

  execute_process(
    COMMAND
      ${CONAN_CMD} install "${CMAKE_SOURCE_DIR}" --profile:host=${_profile}
      --profile:build=${_profile} --output-folder=${CMAKE_BINARY_DIR} --build=missing -s
      build_type=${_conan_build_type}
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
    RESULT_VARIABLE _conan_result)

  if(NOT _conan_result EQUAL 0)
    message(FATAL_ERROR "conan install failed")
  endif()

  file(REMOVE "${CMAKE_SOURCE_DIR}/CMakeUserPresets.json")
endif()

set(CMAKE_TOOLCHAIN_FILE
    "${CMAKE_BINARY_DIR}/generators/conan_toolchain.cmake"
    CACHE STRING "" FORCE)
