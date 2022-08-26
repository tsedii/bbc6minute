#include "mediasAndTranscriptsUrlAddressesPagesDownloader.hpp"

#include <gtest/gtest.h>


TEST (MediasAndTranscriptsUrlAddressesPagesDownloaderTest, GetMediaAndTranscriptDate)
{
    EXPECT_EQ(
        *bbc_6_minute::unit_less_courses::MediasAndTranscriptsUrlAddressesPagesDownloader()
        .GetMediaAndTranscriptDate("/features/6-minute-english/150122")
        , "150122"
    );
}