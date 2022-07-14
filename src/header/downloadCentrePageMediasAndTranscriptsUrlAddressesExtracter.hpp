#pragma once

#include <vector>
#include <memory>
#include <filesystem>


namespace bbc_6_minute
{
    typedef std::vector<std::string> MediasAndTranscriptsUrlAddresses;

    class DownloadCentrePageMediasAndTranscriptsUrlAddressesExtracter
    {
    
    public:
        void ExtractDownloadCentrePageMediasAndTranscriptsUrlAddresses();

    private:
        void GetMediasAndTranscriptsUrlAddresses();

        void DownloadCurrentUnitMediasAndTranscriptsUrlAddresses();

        void CheckFilesExistenceOnFilesystem();

        std::string DownloadFileNameToFilesystemFileName(const std::string& download_file_name);

        std::string UrlAddressToDownloadFileName(const std::string& url_address);

        bool IsFilesystemFileExist(std::filesystem::path& filesystem_file_name);

        void DeleteRedundantSymbols(std::string& filesystem_file_name);

    private:
        std::shared_ptr<MediasAndTranscriptsUrlAddresses> medias_and_transcripts_url_addresses_ptr_{nullptr};
        const std::string string_extract_file_name_template_{"[^<]*<a href=\"([^\"]*)\">Download"};
    };
    
}