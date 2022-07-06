#include "missingFiles.hpp"


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
    {}
}