function(alcia_enable_iwyu target)
  find_program(IWYU_EXE include-what-you-use)
  if(NOT IWYU_EXE)
    message(WARNING "include-what-you-use not found — skipping.")
    return()
  endif()
  set_target_properties(${target} PROPERTIES CXX_INCLUDE_WHAT_YOU_USE
                                             "${IWYU_EXE};-Xiwyu;--cxx17ns;-Xiwyu;--no_fwd_decls")
endfunction()
