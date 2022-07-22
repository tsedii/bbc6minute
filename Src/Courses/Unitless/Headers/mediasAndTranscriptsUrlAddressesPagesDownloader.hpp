#pragma once

#include <string>


namespace bbc_6_minute
{
    class MediasAndTranscriptsUrlAddressesPagesDownloader
    {
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
    };
}