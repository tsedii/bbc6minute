#include "currentUnitMediasAndTranscriptsDownloader.hpp"
#include "missingFiles.hpp"
#include "downloader.hpp"


namespace bbc_6_minute
{
    void CurrentUnitMediasAndTranscriptsDownloader::DownloadCurrentUnitMediasAndTranscripts()
    {
        for (const auto& [url_addresses_file_name, filesystem_file_name] : (*(MissingFiles().GetMissingFiles())))
        {
            Downloader(url_addresses_file_name, filesystem_file_name.string()).Download();
        }
    }
}