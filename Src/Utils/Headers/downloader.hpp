#pragma once

#include <string>


namespace utils
{
    class Downloader
    {
    
    public:
        Downloader(const std::string& url_addresses, const std::string& filesystem_file_name = std::string(""));

        void Download();

    private:
        const std::string downloader_{"wget "};
        std::string url_addresses_;
        std::string filesystem_file_name_;
    };
}