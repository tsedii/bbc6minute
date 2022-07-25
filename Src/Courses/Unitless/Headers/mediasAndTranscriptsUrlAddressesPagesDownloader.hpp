#pragma once

#include <string>
#include <vector>
#include <set>
#include <memory>


namespace bbc_6_minute
{
    class MediasAndTranscriptsUrlAddressesPagesDownloader
    {
        typedef std::set<std::string> MediaAndTranscriptUrlAddresses;

    public:
        void DownloadMediasAndTranscriptsUrlAddressesPages();

    private:
        void DownloadMediaAndTranscriptUrlAddressesPage(const std::string& media_and_transcript_page_url_address);
        void ExtractMediaAndTranscriptUrlAddresses();
        void DownloadMediaAndTranscript();

    private:
        const std::string medias_and_transcripts_pages_url_addresses_begin_{
            "https://www.bbc.co.uk/learningenglish/english"
        };
        const std::vector<std::string> string_extract_file_name_templates_{
            {"data-feature-item=\"([^\"]*)\" class=\"progress-enabled"}
        
        };
        std::shared_ptr<MediaAndTranscriptUrlAddresses> media_and_transcript_url_addresses_ptr_;
    };
}