#pragma once

#include "common.hpp"

#include <memory>


namespace bbc_6_minute
{

    class DownloadCentrePageMediasAndTranscriptsUrlAddressesExtracter
    {
    
    public:
        void ExtractDownloadCentrePageMediasAndTranscriptsUrlAddresses();

    private:
        std::shared_ptr<MediasAndTranscriptsUrlAddresses> GetMediasAndTranscriptsUrlAddresses();

        void DownloadCurrentUnitMediasAndTranscriptsUrlAddresses();

        void CheckFilesExistenceOnFilesystem(std::shared_ptr<MediasAndTranscriptsUrlAddresses> medias_and_transcripts_url_addresses_ptr);

        std::string DownloadFileNameToFilesystemFileName(const std::string& download_file_name);

        std::string UrlAddressToDownloadFileName(const std::string& url_address);

        bool IsFilesystemFileExist(const std::string& filesystem_file_name);
    };
    
}