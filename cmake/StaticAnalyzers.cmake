function(alcia_enable_cppcheck)
  find_program(CPPCHECK_EXE cppcheck)
  if(NOT CPPCHECK_EXE)
    message(WARNING "cppcheck not found — skipping.")
    return()
  endif()

  set(CMAKE_CXX_CPPCHECK
      "${CPPCHECK_EXE}"
      "--enable=all"
      "--suppress=missingInclude"
      "--suppress=unmatchedSuppression"
      "--inline-suppr"
      "--error-exitcode=1"
      "--std=c++23"
      PARENT_SCOPE)
endfunction()
