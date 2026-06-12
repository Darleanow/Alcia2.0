function(alcia_enable_clang_tidy)
  find_program(CLANG_TIDY_EXE NAMES clang-tidy clang-tidy-18 clang-tidy-17)
  if(NOT CLANG_TIDY_EXE)
    message(WARNING "clang-tidy not found — skipping.")
    return()
  endif()
  set(CMAKE_CXX_CLANG_TIDY
      "${CLANG_TIDY_EXE}" "--config-file=${CMAKE_SOURCE_DIR}/.clang-tidy"
      "--header-filter=${CMAKE_SOURCE_DIR}/include/.*"
      PARENT_SCOPE)
endfunction()
