#pragma once

#include <set>
#include <string>
#include <memory>
#include <vector>


namespace bbc_6_minute
{
    namespace unit_less_courses
    {
        typedef std::set<std::string> MediasAndTranscriptsPagesUrlAddresses;

        class MediasAndTranscriptsPagesUrlAddressesExtracter
        {
        public:
            void ExtractMediasAndTranscriptsPagesUrlAddresses();
            std::shared_ptr<MediasAndTranscriptsPagesUrlAddresses> GetMediasAndTranscriptsPagesUrlAddresses();

        private:
            void SaveMediasAndTranscriptsPagesUrlAddresses();

        private:
            static std::shared_ptr<MediasAndTranscriptsPagesUrlAddresses> medias_and_transcripts_pages_url_addresses_ptr_;
            const std::vector<std::string> string_extract_file_name_templates_{
                {"data-feature-item=\"([^\"]*)\" class=\"progress-enabled"}
            };
        };
    }
}