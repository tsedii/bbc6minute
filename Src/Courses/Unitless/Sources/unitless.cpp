# include "unitless.hpp"

#include "mediasAndTranscriptsPagesUrlAddressesPageDownloader.hpp"
#include "mediasAndTranscriptsPagesUrlAddressesExtracter.hpp"


namespace bbc_6_minute
{
    void Unitless::DownloadCourseWithoutUnits()
    {
        MediasAndTranscriptsPagesUrlAddressesPageDownloader().DownloadMediasAndTranscriptsPagesUrlAddressesPage();
        MediasAndTranscriptsPagesUrlAddressesExtracter().ExtractMediasAndTranscriptsPagesUrlAddresses();
    }
}