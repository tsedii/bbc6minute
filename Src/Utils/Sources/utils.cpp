#include "utils.hpp"

#include <iostream>


namespace utils
{
    namespace filesystem
    {
        std::shared_ptr<std::ifstream> GetFileStream(const std::string& file_name)
        {
            std::shared_ptr<std::ifstream> file_stream_ptr;
    
            try
            {
                file_stream_ptr = std::make_shared<std::ifstream>(file_name);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                return nullptr;
            }
            catch(...)
            {
                return nullptr;
            }
            
            return file_stream_ptr;
        }
    
        void CreateMissingSubdirectories(const std::filesystem::path& missing_filesystem_object)
        {
            std::filesystem::path missing_filesystem_object_tmp(missing_filesystem_object);
    
            if (std::filesystem::is_regular_file(missing_filesystem_object_tmp))
            {
                missing_filesystem_object_tmp = missing_filesystem_object_tmp.remove_filename();
            }
            
            if (!IsFilesystemObjectExists(missing_filesystem_object_tmp))
            {
                std::filesystem::create_directories(missing_filesystem_object_tmp);
            }
        }
    
        bool RemoveFile(const std::filesystem::path& file_name)
        {
            try
            {
                if (std::filesystem::exists(file_name))
                {
                    std::filesystem::remove(file_name);
                }
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                return false;
            }
            catch(...)
            {
                return false;
            }
    
            return true;       
        }
    
        bool IsFilesystemObjectExists(const std::filesystem::path& filesystem_object)
        {
            return std::filesystem::exists(filesystem_object);
        }
    }
}