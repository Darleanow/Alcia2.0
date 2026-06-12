set(CTEST_CUSTOM_COVERAGE_EXCLUDE ".*/tests/.*" ".*/build/.*" ".*/conan_provider.*" "/usr/.*"
                                  ".*/Qt/.*")

set(CTEST_CUSTOM_MEMCHECK_IGNORE "AlciaIntegrationTests")

set(CTEST_CUSTOM_MAXIMUM_PASSED_TEST_OUTPUT_SIZE 2048)
set(CTEST_CUSTOM_MAXIMUM_FAILED_TEST_OUTPUT_SIZE 32768)
set(CTEST_NIGHTLY_START_TIME "02:00:00 UTC")
