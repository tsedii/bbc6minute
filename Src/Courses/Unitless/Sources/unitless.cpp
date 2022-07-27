# include "unitless.hpp"

#include "currentCourse.hpp"
#include "mediasAndTranscriptsPagesUrlAddressesPageDownloader.hpp"
#include "mediasAndTranscriptsPagesUrlAddressesExtracter.hpp"
#include "mediasAndTranscriptsUrlAddressesPagesDownloader.hpp"


namespace bbc_6_minute
{
    namespace unit_less_courses
    {
        void Unitless::DownloadCourseWithoutUnits()
        {
            if (CurrentCourse().IsThisCourseWithUnits())
            {
                return;
            }
    
            MediasAndTranscriptsPagesUrlAddressesPageDownloader().DownloadMediasAndTranscriptsPagesUrlAddressesPage();
            MediasAndTranscriptsPagesUrlAddressesExtracter().ExtractMediasAndTranscriptsPagesUrlAddresses();
            MediasAndTranscriptsUrlAddressesPagesDownloader().DownloadMediasAndTranscriptsUrlAddressesPages();
        }
    }
}