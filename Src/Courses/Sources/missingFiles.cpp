#include "missingFiles.hpp"

#include <iostream>

#include "utils.hpp"


namespace bbc_6_minute
{
    std::shared_ptr<MissingFilesForDownload> MissingFiles::missing_files_for_download_ptr_ = nullptr;
    
    void MissingFiles::SaveForDownload(const std::string& medias_and_transcripts_url_addresses_file_name
        , const std::filesystem::path& filesystem_file_name)
    {
        if (!missing_files_for_download_ptr_)
        {
            missing_files_for_download_ptr_ = std::make_shared<MissingFilesForDownload>();
        }
        
        (*missing_files_for_download_ptr_)[medias_and_transcripts_url_addresses_file_name] = filesystem_file_name;
    }
    
    std::shared_ptr<MissingFilesForDownload> MissingFiles::GetMissingFiles()
    {
        PrepareFilesystemForMissingFilesSaving();
        
        return missing_files_for_download_ptr_;
    }
    
    void MissingFiles::PrepareFilesystemForMissingFilesSaving()
    {
        if (!missing_files_for_download_ptr_)
        {
            return;
        }

        if ((*missing_files_for_download_ptr_).empty())
        {
            return;
        }
        
        std::set<std::filesystem::path> files_pathes;
        
        for (const auto& [url_addresses_file_name, filesystem_file_name] : (*missing_files_for_download_ptr_))
        {
            files_pathes.insert(std::filesystem::path(filesystem_file_name).remove_filename());
        }

        CreateMissingSubdirectories(files_pathes);
    }

    void MissingFiles::CreateMissingSubdirectories(const std::set<std::filesystem::path> missing_files_pathes)
    {
        for (const auto& missing_file_path : missing_files_pathes)
        {
            utils::CreateMissingSubdirectories(missing_file_path);
        } 
    }
}