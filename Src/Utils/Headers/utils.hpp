#pragma once

#include <memory>
#include <fstream>
#include <string>
#include <filesystem>


namespace utils
{
    namespace filesystem
    {
        std::shared_ptr<std::fstream> GetFileStream ( const std::string& file_name
            , std::ios_base::openmode mode = std::ios::in | std::ios::out
        );

        void CreateMissingSubdirectories(const std::filesystem::path& missing_filesystem_object);
    
        bool RemoveFile(const std::filesystem::path& file_name);
    
        bool IsFilesystemObjectExists(const std::filesystem::path& filesystem_object);

        std::shared_ptr<std::string> UrlAddressToDownloadFileName(const std::string& url_address);
    }

    namespace string
    {
        std::shared_ptr<std::string> SingleExtractSubstringFromString(
            const std::string& string
            , const std::string& substring_regex_template
        );
    }

    namespace date
    {
        std::shared_ptr<std::string> DdMmYyyyDateToYyMmDd(const std::string& dd_mm_yyyy_date);
    }
}