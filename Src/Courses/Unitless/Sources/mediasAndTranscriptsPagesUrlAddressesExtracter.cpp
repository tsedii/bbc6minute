#include "mediasAndTranscriptsPagesUrlAddressesExtracter.hpp"

#include <iostream>
#include <fstream>
#include <regex>

#include "mediasAndTranscriptsPagesUrlAddressesPageDownloader.hpp"


namespace bbc_6_minute
{
    std::shared_ptr<MediasAndTranscriptsPagesUrlAddresses> MediasAndTranscriptsPagesUrlAddressesExtracter::
        medias_and_transcripts_pages_url_addresses_ptr_ = nullptr;

    void MediasAndTranscriptsPagesUrlAddressesExtracter::ExtractMediasAndTranscriptsPagesUrlAddresses()
    {
        SaveMediasAndTranscriptsPagesUrlAddresses();
        OutputMediasAndTranscriptsPagesUrlAddresses();
    }

    std::shared_ptr<MediasAndTranscriptsPagesUrlAddresses> MediasAndTranscriptsPagesUrlAddressesExtracter::
        GetMediasAndTranscriptsPagesUrlAddresses()
    {
        return medias_and_transcripts_pages_url_addresses_ptr_;
    }

    void MediasAndTranscriptsPagesUrlAddressesExtracter::SaveMediasAndTranscriptsPagesUrlAddresses()
    {
        std::shared_ptr<std::ifstream> medias_and_transcripts_url_addresses_file_stream_ptr 
            = GetMediasAndTranscriptsUrlAddressesFileStream();
        
        if (!medias_and_transcripts_url_addresses_file_stream_ptr)
        {
            return;
        }
        
        if (!medias_and_transcripts_pages_url_addresses_ptr_)
        {
            medias_and_transcripts_pages_url_addresses_ptr_ = std::make_shared<MediasAndTranscriptsPagesUrlAddresses>();
        }

        std::string medias_and_transcripts_url_addresses_file_line;

        try
        {
            while (std::getline(*medias_and_transcripts_url_addresses_file_stream_ptr, medias_and_transcripts_url_addresses_file_line))
            {
                if (medias_and_transcripts_url_addresses_file_line.find("/6-minute-english") == std::string::npos)
                {
                    continue;
                }

                /*
                std::regex_search cause Segmentation fault when trying to process too big std::string().size() = 269553
                
                std::cout << medias_and_transcripts_url_addresses_file_line.size() << std::endl;
                */

                for (const auto& string_extract_file_name_template : string_extract_file_name_templates_)
                {
                    std::regex regex_extract_file_name_template(string_extract_file_name_template);

                    std::smatch match;

                    std::string::const_iterator search_start( medias_and_transcripts_url_addresses_file_line.cbegin() );

                    while (std::regex_search(search_start, medias_and_transcripts_url_addresses_file_line.cend(), match, regex_extract_file_name_template))
                    {
                        medias_and_transcripts_pages_url_addresses_ptr_->insert(match[1].str());
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

    std::shared_ptr<std::ifstream> MediasAndTranscriptsPagesUrlAddressesExtracter::GetMediasAndTranscriptsUrlAddressesFileStream()
    {
        std::shared_ptr<std::ifstream> medias_and_transcripts_url_addresses_file_stream_ptr;

        try
        {
            medias_and_transcripts_url_addresses_file_stream_ptr = std::make_shared<std::ifstream>(
                *(MediasAndTranscriptsPagesUrlAddressesPageDownloader().GetMediasAndTranscriptsPagesUrlAddressesPageFilename())
            );
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return nullptr;
        }
        catch(...)
        {
            return nullptr;
        }
        
        return medias_and_transcripts_url_addresses_file_stream_ptr;
    }

    void MediasAndTranscriptsPagesUrlAddressesExtracter::OutputMediasAndTranscriptsPagesUrlAddresses()
    {
        if (!medias_and_transcripts_pages_url_addresses_ptr_)
        {
            return;
        }

        std::cout << "OutputMediasAndTranscriptsPagesUrlAddresses: " << std::endl << std::endl;

        for (auto const& medias_and_transcripts_pages_url_address : *medias_and_transcripts_pages_url_addresses_ptr_)
        {
            std::cout << medias_and_transcripts_pages_url_address << std::endl;
        }
        
        
    }
}