if(ALCIA_ENABLE_TESTS)
  include(GoogleTest)

  add_executable(AlciaUnitTests unit/test_CommandParser.cpp unit/test_Player.cpp
                                unit/test_World.cpp)
  target_link_libraries(AlciaUnitTests PRIVATE AlciaLib GTest::gtest_main GTest::gmock Qt6::Core
                                               Qt6::Test)
  alcia_set_warnings(AlciaUnitTests)
  gtest_discover_tests(
    AlciaUnitTests
    PROPERTIES LABELS "unit"
    TIMEOUT 30 FAIL_REGULAR_EXPRESSION "Segmentation fault|Aborted|AddressSanitizer|runtime error"
               DISCOVERY_TIMEOUT 30)

  add_executable(AlciaIntegrationTests integration/test_EngineIntegration.cpp)
  target_link_libraries(AlciaIntegrationTests PRIVATE AlciaLib GTest::gtest_main Qt6::Core
                                                      Qt6::Widgets Qt6::Test)
  alcia_set_warnings(AlciaIntegrationTests)
  gtest_discover_tests(
    AlciaIntegrationTests
    PROPERTIES LABELS "integration"
    TIMEOUT 60 FAIL_REGULAR_EXPRESSION "Segmentation fault|Aborted|AddressSanitizer|runtime error"
               DISCOVERY_TIMEOUT 30)
endif()

if(ALCIA_ENABLE_BENCHMARKS)
  alcia_setup_benchmarks(bench/bench_CommandParser.cpp)
endif()

if(ALCIA_ENABLE_FUZZING)
  add_executable(FuzzCommandParser fuzz/fuzz_CommandParser.cpp)
  target_link_libraries(FuzzCommandParser PRIVATE AlciaLib Qt6::Core)
  target_compile_options(FuzzCommandParser PRIVATE -fsanitize=fuzzer)
  target_link_options(FuzzCommandParser PRIVATE -fsanitize=fuzzer)
endif()

if(ALCIA_ENABLE_COVERAGE)
  alcia_add_coverage_target()
endif()
