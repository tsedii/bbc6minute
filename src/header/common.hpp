#pragma once

#include <vector>
#include <map>
#include <string>
#include <filesystem>


namespace bbc_6_minute
{
    typedef std::vector<std::string> MediasAndTranscriptsUrlAddresses;

    typedef std::map<std::string, std::filesystem::path> MissingFilesForDownload;

    const std::string string_extract_file_name_template{"[^<]*<a href=\"([^\"]*)\">Download"};
}