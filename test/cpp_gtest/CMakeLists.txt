set(TEST_NAME CashierTests)
add_executable(${TEST_NAME} CashierTests.cc)
target_link_libraries(${TEST_NAME} PRIVATE GildedRoseLib GTest::gtest_main)
set_property(TARGET ${TEST_NAME} PROPERTY CXX_STANDARD 11)

add_test(
  NAME ${TEST_NAME}
  COMMAND ${TEST_NAME}
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
