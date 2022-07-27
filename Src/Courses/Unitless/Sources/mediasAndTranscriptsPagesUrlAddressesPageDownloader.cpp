#include "mediasAndTranscriptsPagesUrlAddressesPageDownloader.hpp"

#include <filesystem>

#include "currentCourse.hpp"
#include "downloader.hpp"
#include "utils.hpp"


namespace bbc_6_minute
{
    void MediasAndTranscriptsPagesUrlAddressesPageDownloader::DownloadMediasAndTranscriptsPagesUrlAddressesPage()
    {
        utils::RemoveFile(url_addresses_page_file_name_);

        Downloader(
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