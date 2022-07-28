#pragma once

#include <string>
#include <vector>
#include <set>
#include <memory>
#include <filesystem>


namespace bbc_6_minute
{
    namespace unit_less_courses
    {
        typedef std::set<std::string> MediaAndTranscriptUrlAddresses;

        class MediasAndTranscriptsUrlAddressesPagesDownloader
        {
        public:
            void DownloadMediasAndTranscriptsUrlAddressesPages();

        private:
            void DownloadMediaAndTranscriptUrlAddressesPage(const std::string& media_and_transcript_page_url_address);
            void ExtractMediaAndTranscriptUrlAddresses();

        private:
            const std::string medias_and_transcripts_pages_url_addresses_begin_{
                "https://www.bbc.co.uk/learningenglish/english"
            };
            const std::vector<std::string> string_extract_file_name_templates_{
                {"bbcle-download-extension-pdf\" href=\"([^\"]*)\"><span  data-i18n-message-id=\"Download PDF"}
                , {"bbcle-download-extension-mp3\" href=\"([^\"]*)\"><span  data-i18n-message-id=\"Download Audio"}
            };
            std::shared_ptr<MediaAndTranscriptUrlAddresses> media_and_transcript_url_addresses_ptr_{nullptr};
        };
    }
}