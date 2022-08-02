cmake_minimum_required( VERSION 3.11 )

add_executable(bbc6minuteTest gTestsMain.cpp)

target_link_libraries(bbc6minuteTest gtest gmock pthread)