#include "mediasAndTranscriptsUrlAddressesPagesDownloader.hpp"

#include <filesystem>
#include <regex>
#include <iostream>

#include "mediasAndTranscriptsPagesUrlAddressesExtracter.hpp"
#include "downloader.hpp"
#include "mediasAndTranscriptsPagesUrlAddressesPageDownloader.hpp"
#include "utils.hpp"
#include "mediaAndTranscriptDownloader.hpp"


namespace bbc_6_minute
{
    namespace unit_less_courses
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

            for (auto const& media_and_transcript_page_url_address_last_part : *medias_and_transcripts_pages_url_addresses_ptr)
            {
                DownloadMediaAndTranscriptUrlAddressesPage(media_and_transcript_page_url_address_last_part);
                ExtractMediaAndTranscriptUrlAddresses();
                MediaAndTranscriptDownloader(
                    media_and_transcript_url_addresses_ptr_
                    , GetMediaAndTranscriptDate(media_and_transcript_page_url_address_last_part)
                ).DownloadMediaAndTranscript();
            }
        }

        void MediasAndTranscriptsUrlAddressesPagesDownloader::DownloadMediaAndTranscriptUrlAddressesPage(const std::string& media_and_transcript_page_url_address)
        {
            auto url_addresses_page_file_name{
                *(MediasAndTranscriptsPagesUrlAddressesPageDownloader()
                    .GetMediasAndTranscriptsPagesUrlAddressesPageFilename())
            };

            utils::filesystem::RemoveFile(url_addresses_page_file_name);

            utils::Downloader(
                medias_and_transcripts_pages_url_addresses_begin_ 
                    + media_and_transcript_page_url_address
                , url_addresses_page_file_name
            ).Download();
        }

        void MediasAndTranscriptsUrlAddressesPagesDownloader::ExtractMediaAndTranscriptUrlAddresses()
        {
            std::shared_ptr<std::ifstream> media_and_transcript_url_addresses_file_stream_ptr 
                = utils::filesystem::GetFileStream(
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

        std::shared_ptr<std::string> MediasAndTranscriptsUrlAddressesPagesDownloader
            ::GetMediaAndTranscriptDate(const std::string& media_and_transcript_page_url_address_last_part)
        {
            if (media_and_transcript_page_url_address_last_part.empty())
            {
                return nullptr;
            }
            
            std::shared_ptr<std::string> media_and_transcript_date_ptr{nullptr};
            
            // Extract date for string like "/features/6-minute-english/150122"
            
            media_and_transcript_date_ptr = utils::string::SingleExtractSubstringFromString(
                media_and_transcript_page_url_address_last_part, "/(\\d{6})$"
            );

            if (!media_and_transcript_date_ptr->empty())
            {
                return media_and_transcript_date_ptr;
            }
            
            // Extract date for string like "/features/6-minute-english/ep-02102014"
            
            media_and_transcript_date_ptr = utils::string::SingleExtractSubstringFromString(
                media_and_transcript_page_url_address_last_part, "/ep-(\\d{8})$"
            );

            media_and_transcript_date_ptr = utils::date::DdMmYyyyDateToYyMmDd(*media_and_transcript_date_ptr);

            if (!media_and_transcript_date_ptr->empty())
            {
                return media_and_transcript_date_ptr;
            }

            // Extract date for string like "/features/6-minute-english/ep-141127

            media_and_transcript_date_ptr = utils::string::SingleExtractSubstringFromString(
                media_and_transcript_page_url_address_last_part, "/ep-(\\d{6})$"
            );

            if (!media_and_transcript_date_ptr->empty())
            {
                return media_and_transcript_date_ptr;
            }

            return nullptr;
        }
    }
}