#pragma once

#include "common.hpp"

#include <memory>


namespace bbc_6_minute
{
    std::string GetWgetCommandLine();

    std::shared_ptr<MediasAndTranscriptsUrlAddresses> GetMediasAndTranscriptsUrlAddresses();

    void DownloadCurrentUnitMediasAndTranscriptsUrlAddresses();

    void CheckFilesExistenceOnFilesystem(std::shared_ptr<MediasAndTranscriptsUrlAddresses> medias_and_transcripts_url_addresses_ptr);

    std::string DownloadFileNameToFilesystemFileName(const std::string& download_file_name);
}