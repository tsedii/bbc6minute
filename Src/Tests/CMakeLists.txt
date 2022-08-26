cmake_minimum_required( VERSION 3.11 )

set( TEST_SOURCE_FILES
    gTestsMain.cpp

    Sources/unitlessTests.cpp

    ../Utils/Headers/utils.hpp
    ../Utils/Sources/utils.cpp

    ../Courses/Unitless/Headers/mediasAndTranscriptsUrlAddressesPagesDownloader.hpp
    ../Courses/Unitless/Sources/mediasAndTranscriptsUrlAddressesPagesDownloader.cpp
)

add_executable(bbc6minuteTest ${TEST_SOURCE_FILES})

target_link_libraries(bbc6minuteTest gtest gmock pthread)