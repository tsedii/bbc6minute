#pragma once

#include <set>
#include <string>
#include <memory>
#include <filesystem>


namespace bbc_6_minute
{
    namespace unit_less_courses
    {
        typedef std::set<std::string> MediaAndTranscriptUrlAddresses;

        class MediaAndTranscriptDownloader
        {
        public:
            MediaAndTranscriptDownloader(
                std::shared_ptr<MediaAndTranscriptUrlAddresses> media_and_transcript_url_addresses_ptr
            );
            void DownloadMediaAndTranscript();

        private:
            std::string ExtractDateFromFileName(const std::string& media_or_transcript_url_address);
            std::shared_ptr<std::filesystem::path> GetCurrentSubPath(const std::string& media_or_transcript_url_address);
            void CheckCurrentSubPathExistence(const std::string& media_or_transcript_url_address);

        private:
            std::shared_ptr<MediaAndTranscriptUrlAddresses> media_and_transcript_url_addresses_ptr_{nullptr};
        };
    }
}