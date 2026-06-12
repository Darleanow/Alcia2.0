function(alcia_set_compile_options target)
  target_compile_options(
    ${target}
    PRIVATE $<$<CONFIG:Debug>:-fno-omit-frame-pointer> $<$<CONFIG:Release>:-O3>
            $<$<CONFIG:Release>:-march=native> $<$<CONFIG:RelWithDebInfo>:-O2>
            $<$<CONFIG:RelWithDebInfo>:-fno-omit-frame-pointer>)

  if(NOT MSVC)
    include(CheckIPOSupported)
    check_ipo_supported(RESULT _ipo_supported)
    if(_ipo_supported)
      set_target_properties(${target} PROPERTIES INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE)
    endif()
  endif()
endfunction()
