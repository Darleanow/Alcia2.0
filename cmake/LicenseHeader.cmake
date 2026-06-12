function(alcia_check_license_headers)
  find_program(PYTHON_EXE python3 REQUIRED)

  add_custom_target(
    check-license-headers
    COMMAND ${PYTHON_EXE} "${CMAKE_SOURCE_DIR}/scripts/add_license_header.py" --check
            "${CMAKE_SOURCE_DIR}/src" "${CMAKE_SOURCE_DIR}/include" "${CMAKE_SOURCE_DIR}/tests"
    VERBATIM)

  add_custom_target(
    add-license-headers
    COMMAND ${PYTHON_EXE} "${CMAKE_SOURCE_DIR}/scripts/add_license_header.py"
            "${CMAKE_SOURCE_DIR}/src" "${CMAKE_SOURCE_DIR}/include" "${CMAKE_SOURCE_DIR}/tests"
    VERBATIM)
endfunction()
