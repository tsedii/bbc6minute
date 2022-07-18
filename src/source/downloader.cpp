#include "downloader.hpp"


namespace bbc_6_minute
{
    Downloader::Downloader(const std::string& url_addresses, const std::string& filesystem_file_name)
        :url_addresses_(url_addresses), filesystem_file_name_(filesystem_file_name)
    {
    }
    
    void Downloader::Download()
    {
        std::system(std::string(
            downloader_ 
            + (filesystem_file_name_.empty() ? std::string("") : std::string("-O ") + filesystem_file_name_ + " ")
            + url_addresses_
        ).c_str());
    }
    
}