#pragma once

#include <set>
#include <string>
#include <memory>
#include <vector>


namespace bbc_6_minute
{
    typedef std::set<std::string> MediasAndTranscriptsUrlAddresses;

    class MediasAndTranscriptsPagesUrlAddressesExtracter
    {
    public:
        void ExtractMediasAndTranscriptsPagesUrlAddresses();

    private:
        void GetMediasAndTranscriptsPagesUrlAddresses();
        std::shared_ptr<std::string> GetMediasAndTranscriptsUrlAddressesFileName();
        std::shared_ptr<std::ifstream> GetMediasAndTranscriptsUrlAddressesFileStream();

    private:
        const std::string medias_and_transcripts_url_addresses_file_name_{"6-minute-english"};
        std::shared_ptr<MediasAndTranscriptsUrlAddresses> medias_and_transcripts_url_addresses_ptr_{nullptr};
        const std::vector<std::string> string_extract_file_name_templates_{
            {"[^<]*<a href=\"([^\"]*)\">Download"}
            , {"[^<]*<a class=\"download\" href=\"([^\"]*)\">"}
        };
    };
}