function(alcia_setup_doxygen)
  find_package(Doxygen REQUIRED dot)

  set(DOXYGEN_IN "${CMAKE_SOURCE_DIR}/docs/doxygen/Doxyfile.in")
  set(DOXYGEN_OUT "${CMAKE_BINARY_DIR}/Doxyfile")

  configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

  add_custom_target(
    docs
    COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
    COMMENT "Generating Doxygen documentation"
    VERBATIM)
endfunction()
