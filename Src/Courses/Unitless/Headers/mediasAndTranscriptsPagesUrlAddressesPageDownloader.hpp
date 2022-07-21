#pragma once

#include <string>


namespace bbc_6_minute
{
    class MediasAndTranscriptsPagesUrlAddressesPageDownloader
    {
    public:
        void DownloadMediasAndTranscriptsPagesUrlAddressesPage();

    private:
        const std::string url_addresses_page_file_name_{"urlAddressesPage"};
        const unsigned int units_absence_mark_{0};
    };
}