set(ALCIA_SANITIZER_TYPE
    "address"
    CACHE STRING "address | thread | memory | undefined")

function(alcia_enable_sanitizers)
  if(MSVC)
    return()
  endif()

  set(type "${ALCIA_SANITIZER_TYPE}")

  if(type STREQUAL "address")
    add_compile_options(-fsanitize=address,undefined -fno-omit-frame-pointer -g)
    add_link_options(-fsanitize=address,undefined)
  elseif(type STREQUAL "thread")
    add_compile_options(-fsanitize=thread -fno-omit-frame-pointer -g)
    add_link_options(-fsanitize=thread)
  elseif(type STREQUAL "memory")
    add_compile_options(-fsanitize=memory -fno-omit-frame-pointer -g)
    add_link_options(-fsanitize=memory)
  elseif(type STREQUAL "undefined")
    add_compile_options(-fsanitize=undefined -fno-omit-frame-pointer -g)
    add_link_options(-fsanitize=undefined)
  else()
    message(
      FATAL_ERROR
        "Unknown ALCIA_SANITIZER_TYPE '${type}' — valid: address | thread | memory | undefined")
  endif()
endfunction()
