#include "mediasAndTranscriptsPagesUrlAddressesExtracter.hpp"

#include <iostream>
#include <fstream>
#include <regex>


namespace bbc_6_minute
{
    void MediasAndTranscriptsPagesUrlAddressesExtracter::ExtractMediasAndTranscriptsPagesUrlAddresses()
    {
        GetMediasAndTranscriptsPagesUrlAddresses();
    }

    void MediasAndTranscriptsPagesUrlAddressesExtracter::GetMediasAndTranscriptsPagesUrlAddresses()
    {
        std::shared_ptr<std::ifstream> medias_and_transcripts_url_addresses_file_stream_ptr 
            = GetMediasAndTranscriptsUrlAddressesFileStream();
        
        if (!medias_and_transcripts_url_addresses_file_stream_ptr)
        {
            return;
        }
        
        if (!medias_and_transcripts_url_addresses_ptr_)
        {
            medias_and_transcripts_url_addresses_ptr_ = std::make_shared<MediasAndTranscriptsUrlAddresses>();
        }

        std::string medias_and_transcripts_url_addresses_file_line;

        try
        {
            while (std::getline(*medias_and_transcripts_url_addresses_file_stream_ptr, medias_and_transcripts_url_addresses_file_line))
            {
                if (!(medias_and_transcripts_url_addresses_file_line.find(".pdf") != std::string::npos 
                    or medias_and_transcripts_url_addresses_file_line.find(".mp3") != std::string::npos))
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
                        medias_and_transcripts_url_addresses_ptr_->insert(match[1].str());
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

    std::shared_ptr<std::string> MediasAndTranscriptsPagesUrlAddressesExtracter::GetMediasAndTranscriptsUrlAddressesFileName()
    {
        return std::make_shared<std::string>(medias_and_transcripts_url_addresses_file_name_);
    }

    std::shared_ptr<std::ifstream> MediasAndTranscriptsPagesUrlAddressesExtracter::GetMediasAndTranscriptsUrlAddressesFileStream()
    {
        std::shared_ptr<std::ifstream> medias_and_transcripts_url_addresses_file_stream_ptr;

        try
        {
            medias_and_transcripts_url_addresses_file_stream_ptr = std::make_shared<std::ifstream>(*(GetMediasAndTranscriptsUrlAddressesFileName()));
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
}