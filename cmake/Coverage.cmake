function(alcia_enable_coverage)
  if(NOT CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    message(WARNING "Coverage only supported with GCC or Clang.")
    return()
  endif()
  add_compile_options(--coverage -O0 -g)
  add_link_options(--coverage)
endfunction()

function(alcia_add_coverage_target)
  find_program(LCOV_EXE lcov)
  find_program(GENHTML_EXE genhtml)
  if(NOT LCOV_EXE OR NOT GENHTML_EXE)
    message(WARNING "lcov/genhtml not found — no coverage target.")
    return()
  endif()

  add_custom_target(
    coverage
    COMMAND ${LCOV_EXE} --directory . --zerocounters
    COMMAND ${CMAKE_CTEST_COMMAND} --preset coverage -j4 || true
    COMMAND ${LCOV_EXE} --directory . --capture --output-file coverage.info --exclude "*/tests/*"
            --exclude "*/build/*" --exclude "/usr/*"
    COMMAND ${GENHTML_EXE} coverage.info --output-directory coverage_html
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
    COMMENT "Coverage report → build/coverage_html/index.html")
endfunction()
