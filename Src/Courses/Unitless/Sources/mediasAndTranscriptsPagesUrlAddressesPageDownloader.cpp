#include "mediasAndTranscriptsPagesUrlAddressesPageDownloader.hpp"

#include <filesystem>

#include "currentCourse.hpp"
#include "downloader.hpp"
#include "utils.hpp"


namespace bbc_6_minute
{
    namespace unit_less_courses
    {
        void MediasAndTranscriptsPagesUrlAddressesPageDownloader::DownloadMediasAndTranscriptsPagesUrlAddressesPage()
        {
            utils::filesystem::RemoveFile(url_addresses_page_file_name_);

            utils::Downloader(
                CurrentCourse().GetCurrentCourseDownloadCentrePageUrlAddress(units_absence_mark_)
                , url_addresses_page_file_name_
            ).Download();
        }

        std::shared_ptr<std::string> MediasAndTranscriptsPagesUrlAddressesPageDownloader::
            GetMediasAndTranscriptsPagesUrlAddressesPageFilename()
        {
            return std::make_shared<std::string>(url_addresses_page_file_name_);
        }
    }
}