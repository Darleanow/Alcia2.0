qt_add_library(
  AlciaLib
  STATIC
  core/Engine.cpp
  game/World.cpp
  game/Player.cpp
  game/CommandParser.cpp
  ui/ConsoleRenderer.cpp
  ${PROJECT_SOURCE_DIR}/include/Alcia/core/Engine.hpp
  ${PROJECT_SOURCE_DIR}/include/Alcia/game/World.hpp
  ${PROJECT_SOURCE_DIR}/include/Alcia/game/Player.hpp
  ${PROJECT_SOURCE_DIR}/include/Alcia/game/CommandParser.hpp
  ${PROJECT_SOURCE_DIR}/include/Alcia/ui/ConsoleRenderer.hpp)

target_include_directories(AlciaLib PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                                           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

set_target_properties(AlciaLib PROPERTIES AUTOMOC ON)

target_link_libraries(AlciaLib PUBLIC Qt6::Core Qt6::Widgets)

alcia_set_warnings(AlciaLib)
alcia_set_compile_options(AlciaLib)

qt_add_executable(Alcia main.cpp)

target_link_libraries(Alcia PRIVATE AlciaLib)

alcia_set_warnings(Alcia)
alcia_set_compile_options(Alcia)

if(ALCIA_ENABLE_HARDENING)
  alcia_enable_hardening(Alcia)
endif()

if(ALCIA_ENABLE_IWYU)
  alcia_enable_iwyu(AlciaLib)
  alcia_enable_iwyu(Alcia)
endif()

install(TARGETS Alcia RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
