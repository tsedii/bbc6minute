#include "supportingTools.hpp"

#include "currentUnitPageUrlAddress.hpp"

#include <fstream>
#include <regex>
#include <iostream>


namespace bbc_6_minute
{

    std::string GetWgetCommandLine()
    {
        return std::string("wget ") + CurrentUnitPageUrlAddress().GetUrlAddress();
    }

    std::shared_ptr<MediasAndTranscriptsUrlAddresses> GetMediasAndTranscriptsUrlAddresses()
    {
        std::string medias_and_transcripts_url_addresses_file_line;
        std::ifstream medias_and_transcripts_url_addresses_file_stream(bbc_6_minute::medias_and_transcripts_url_addresses_file_name);

        std::shared_ptr<MediasAndTranscriptsUrlAddresses> medias_and_transcripts_url_addresses_ptr(std::make_shared<MediasAndTranscriptsUrlAddresses>());

        std::regex regex_extract_file_name_template(bbc_6_minute::string_extract_file_name_template);

        try
        {
            while (std::getline(medias_and_transcripts_url_addresses_file_stream, medias_and_transcripts_url_addresses_file_line))
            {
                if (!(medias_and_transcripts_url_addresses_file_line.find(".pdf") != std::string::npos or medias_and_transcripts_url_addresses_file_line.find(".mp3") != std::string::npos))
                {
                    continue;
                }

                /*
                std::regex_search cause Segmentation fault when trying to process too big std::string().size() = 269553
                
                std::cout << medias_and_transcripts_url_addresses_file_line.size() << std::endl;
                */

                std::smatch match;

                std::string::const_iterator search_start( medias_and_transcripts_url_addresses_file_line.cbegin() );

                while (std::regex_search(search_start, medias_and_transcripts_url_addresses_file_line.cend(), match, regex_extract_file_name_template))
                {
                    medias_and_transcripts_url_addresses_ptr->push_back(match[1].str());
                    search_start = match.suffix().first;
                }

            }
            return medias_and_transcripts_url_addresses_ptr;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        catch(...)
        {
            std::cerr << "Unknown error" << '\n';
        }
        return nullptr;
    }

    void DownloadCurrentUnitMediasAndTranscriptsUrlAddresses()
    {
        if (!std::filesystem::exists(bbc_6_minute::medias_and_transcripts_url_addresses_file_name))
        {
            std::system(bbc_6_minute::GetWgetCommandLine().c_str());
        }
    }

    void CheckFilesExistenceOnFilesystem(std::shared_ptr<MediasAndTranscriptsUrlAddresses> medias_and_transcripts_url_addresses_file_names_ptr)
    {
        for(const auto& medias_and_transcripts_url_addresses_file_name : (*medias_and_transcripts_url_addresses_file_names_ptr))
        {
            DownloadFileNameToFilesystemFileName(medias_and_transcripts_url_addresses_file_name);
        }
    }

    std::string DownloadFileNameToFilesystemFileName(const std::string& download_file_name)
    {
        const size_t second_symbol_position = 1;
        const size_t symbols_number = 1;

        std::string filesystem_file_name(download_file_name);

        if(filesystem_file_name[2] == '_')
        {
            filesystem_file_name.insert(second_symbol_position, symbols_number, '0');
        }

        filesystem_file_name.insert(second_symbol_position - 1, symbols_number, '_');
        filesystem_file_name.insert(second_symbol_position - 1, symbols_number, std::to_string(static_cast<int>(course_number))[0]);
        filesystem_file_name.insert(second_symbol_position - 1, symbols_number, 'c');

        return filesystem_file_name;
    }

    std::string UrlAddressToDownloadFileName(const std::string& url_address)
    {
        std::string download_file_name(url_address);
        return download_file_name.substr(download_file_name.find_last_of('/') + 1);
    }

    bool IsFilesystemFileExist(const std::string& filesystem_file_name)
    {
        return false;
    }

}