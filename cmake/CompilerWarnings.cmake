function(alcia_set_warnings target)
  set(MSVC_WARNINGS /W4 /WX /permissive- /w14640 /w14826 /w14928)
  set(COMMON_WARNINGS
      -Wall
      -Wextra
      -Wpedantic
      -Werror
      -Wshadow
      -Wnon-virtual-dtor
      -Wold-style-cast
      -Wcast-align
      -Wunused
      -Woverloaded-virtual
      -Wconversion
      -Wsign-conversion
      -Wnull-dereference
      -Wdouble-promotion
      -Wformat=2
      -Wimplicit-fallthrough)
  set(CLANG_WARNINGS ${COMMON_WARNINGS} -Wlifetime)
  set(GCC_WARNINGS ${COMMON_WARNINGS} -Wmisleading-indentation -Wduplicated-cond
                   -Wduplicated-branches -Wlogical-op -Wuseless-cast)

  if(MSVC)
    target_compile_options(${target} PRIVATE ${MSVC_WARNINGS})
  elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(${target} PRIVATE ${CLANG_WARNINGS})
  else()
    target_compile_options(${target} PRIVATE ${GCC_WARNINGS})
  endif()
endfunction()
