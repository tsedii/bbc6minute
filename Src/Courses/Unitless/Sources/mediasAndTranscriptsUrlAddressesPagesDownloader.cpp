#include "mediasAndTranscriptsUrlAddressesPagesDownloader.hpp"

#include <filesystem>

#include "mediasAndTranscriptsPagesUrlAddressesExtracter.hpp"
#include "downloader.hpp"
#include "mediasAndTranscriptsPagesUrlAddressesPageDownloader.hpp"


namespace bbc_6_minute
{
    void MediasAndTranscriptsUrlAddressesPagesDownloader::DownloadMediasAndTranscriptsUrlAddressesPages()
    {
        std::shared_ptr<MediasAndTranscriptsPagesUrlAddresses> medias_and_transcripts_pages_url_addresses_ptr{
            MediasAndTranscriptsPagesUrlAddressesExtracter().GetMediasAndTranscriptsPagesUrlAddresses()
        };

        if (!medias_and_transcripts_pages_url_addresses_ptr)
        {
            return;
        }
        
        for (auto const& media_and_transcript_page_url_address : *medias_and_transcripts_pages_url_addresses_ptr)
        {
            DownloadMediaAndTranscriptUrlAddressesPage(media_and_transcript_page_url_address);
            ExtractMediaAndTranscriptUrlAddresses();
            DownloadMediaAndTranscript();
            return; // debug instruction
        }
    }

    void MediasAndTranscriptsUrlAddressesPagesDownloader::DownloadMediaAndTranscriptUrlAddressesPage(const std::string& media_and_transcript_page_url_address)
    {
        auto url_addresses_page_file_name{
            *(MediasAndTranscriptsPagesUrlAddressesPageDownloader()
            .GetMediasAndTranscriptsPagesUrlAddressesPageFilename())
        };

        if (std::filesystem::exists(url_addresses_page_file_name))
        {
            std::filesystem::remove(url_addresses_page_file_name);
        }

        Downloader(
            medias_and_transcripts_pages_url_addresses_begin_ 
            + media_and_transcript_page_url_address
            , url_addresses_page_file_name
        ).Download();
    }

    void MediasAndTranscriptsUrlAddressesPagesDownloader::ExtractMediaAndTranscriptUrlAddresses()
    {}

    void MediasAndTranscriptsUrlAddressesPagesDownloader::DownloadMediaAndTranscript()
    {}
}