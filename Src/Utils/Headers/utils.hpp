#pragma once

#include <memory>
#include <fstream>
#include <string>
#include <filesystem>


namespace utils
{
    std::shared_ptr<std::ifstream> GetFileStream(const std::string& file_name);

    void CreateMissingSubdirectories(const std::filesystem::path& missing_filesystem_object);

    bool RemoveFile(const std::filesystem::path& file_name);

    bool IsFilesystemObjectExists(const std::filesystem::path& filesystem_object);
}