#pragma once

#include <string>
#include <memory>


namespace bbc_6_minute
{
    namespace unit_less_courses
    {
        class MediasAndTranscriptsPagesUrlAddressesPageDownloader
        {
        public:
            void DownloadMediasAndTranscriptsPagesUrlAddressesPage();
            std::shared_ptr<std::string> GetMediasAndTranscriptsPagesUrlAddressesPageFilename();
    
        private:
            const std::string url_addresses_page_file_name_{"urlAddressesPage"};
            const unsigned int units_absence_mark_{0};
        };
    }
}