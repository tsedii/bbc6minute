#include "mediasAndTranscriptsUrlAddressesPagesDownloader.hpp"

#include <filesystem>
#include <regex>
#include <iostream>

#include "mediasAndTranscriptsPagesUrlAddressesExtracter.hpp"
#include "downloader.hpp"
#include "mediasAndTranscriptsPagesUrlAddressesPageDownloader.hpp"
#include "utils.hpp"


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

        utils::RemoveFile(url_addresses_page_file_name);

        Downloader(
            medias_and_transcripts_pages_url_addresses_begin_ 
                + media_and_transcript_page_url_address
            , url_addresses_page_file_name
        ).Download();
    }

    void MediasAndTranscriptsUrlAddressesPagesDownloader::ExtractMediaAndTranscriptUrlAddresses()
    {
        std::shared_ptr<std::ifstream> media_and_transcript_url_addresses_file_stream_ptr 
            = utils::GetFileStream(
                *(MediasAndTranscriptsPagesUrlAddressesPageDownloader()
                    .GetMediasAndTranscriptsPagesUrlAddressesPageFilename()
                )
            );
        
        if (!media_and_transcript_url_addresses_file_stream_ptr)
        {
            return;
        }
        
        if (!media_and_transcript_url_addresses_ptr_)
        {
            media_and_transcript_url_addresses_ptr_ = std::make_shared<MediaAndTranscriptUrlAddresses>();
        }

        std::string media_and_transcript_url_addresses_file_line;

        try
        {
            while (std::getline(*media_and_transcript_url_addresses_file_stream_ptr, media_and_transcript_url_addresses_file_line))
            {
                if (media_and_transcript_url_addresses_file_line.find(".pdf") == std::string::npos
                    and media_and_transcript_url_addresses_file_line.find(".mp3") == std::string::npos
                )
                {
                    continue;
                }

                for (const auto& string_extract_file_name_template : string_extract_file_name_templates_)
                {
                    std::regex regex_extract_file_name_template(string_extract_file_name_template);

                    std::smatch match;

                    std::string::const_iterator search_start( media_and_transcript_url_addresses_file_line.cbegin() );

                    while (std::regex_search(search_start, media_and_transcript_url_addresses_file_line.cend(), match, regex_extract_file_name_template))
                    {
                        media_and_transcript_url_addresses_ptr_->insert(match[1].str());
                        search_start = match.suffix().first;
                    }
                }

            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        catch(...)
        {
            std::cerr << "Unknown error" << '\n';
        }
    }

    std::string MediasAndTranscriptsUrlAddressesPagesDownloader::ExtractDateFromFileName()
    {
        if (!media_and_transcript_url_addresses_ptr_)
        {
            return std::string();
        }

        std::regex regex_extract_date_template("/(\\d{6})_");

        std::smatch match;

        std::regex_search(
            (media_and_transcript_url_addresses_ptr_->cbegin())->cbegin()
            , (media_and_transcript_url_addresses_ptr_->cbegin())->cend()
            , match
            , regex_extract_date_template
        );

        return match[1].str();
    }

    std::shared_ptr<std::filesystem::path> MediasAndTranscriptsUrlAddressesPagesDownloader::GetCurrentSubPath()
    {
        std::string sub_path(ExtractDateFromFileName());

        if (sub_path.empty())
        {
            return nullptr;
        }
        
        const unsigned int two_digit_year_designation{2};

        // trims from the argument-valued position to the end of the string
        sub_path.erase(two_digit_year_designation);

        const unsigned int string_begin_position{0};

        return std::make_shared<std::filesystem::path>(
                   sub_path.insert(string_begin_position, "20")
               );
    }

    void MediasAndTranscriptsUrlAddressesPagesDownloader::CheckCurrentSubPathExistence()
    {
        /**(CurrentCourse().GetCurrentCoursePath())
            / GetCurrentSubPath*/
    }

    void MediasAndTranscriptsUrlAddressesPagesDownloader::CheckMediaAndTranscriptFilesExistence()
    {}

    void MediasAndTranscriptsUrlAddressesPagesDownloader::DownloadMediaAndTranscript()
    {}
}