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
                , std::shared_ptr<std::string> media_and_transcript_date_ptr
            );
            
            void DownloadMediaAndTranscript();

        private:
            std::shared_ptr<std::string> ExtractDateFromFileName();

            void DeleteRedundantSymbols(std::string& filesystem_file_name);

            std::shared_ptr<std::filesystem::path> GetCurrentSubPath(
                const std::string& media_or_transcript_url_address
            );
            
            std::shared_ptr<std::filesystem::path> CreateCurrentFileFolderIfNecessaryAndGetItFullPath(
                const std::string& media_or_transcript_url_address
            );
            
            std::shared_ptr<std::filesystem::path> GetCurrentFileFilesystemFilename(
                const std::string& media_or_transcript_url_address
            );
            
            void DownloadCurrentFile(
                const std::filesystem::path& current_file_full_path
                , const std::string& media_or_transcript_url_address
            );

        private:
            std::shared_ptr<MediaAndTranscriptUrlAddresses> media_and_transcript_url_addresses_ptr_{nullptr};
            std::shared_ptr<std::string> media_and_transcript_date_ptr_;
        };
    }
}