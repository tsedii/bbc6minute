#pragma once

#include "common.hpp"

#include <set>


namespace bbc_6_minute
{
    class MissingFiles
    {
    public:
        void SaveForDownload(const std::string& medias_and_transcripts_url_addresses_file_name
            , const std::filesystem::path& filesystem_file_name);
        
        std::shared_ptr<MissingFilesForDownload> GetMissingFiles();

    private:
        void PrepareFilesystemForMissingFilesSaving();
        void CreateMissingSubdirectories(const std::set<std::filesystem::path> missing_files_pathes);

    private:
        static std::shared_ptr<MissingFilesForDownload> missing_files_for_download_ptr_;
    };
}