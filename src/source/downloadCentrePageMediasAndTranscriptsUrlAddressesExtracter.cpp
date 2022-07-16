#include "downloadCentrePageMediasAndTranscriptsUrlAddressesExtracter.hpp"
#include "currentUnit.hpp"
#include "missingFiles.hpp"
#include "currentCourse.hpp"

#include <fstream>
#include <regex>
#include <iostream>


namespace bbc_6_minute
{
    void DownloadCentrePageMediasAndTranscriptsUrlAddressesExtracter::ExtractDownloadCentrePageMediasAndTranscriptsUrlAddresses()
    {
        GetMediasAndTranscriptsUrlAddresses();

        CheckFilesExistenceOnFilesystem();
    }

    void DownloadCentrePageMediasAndTranscriptsUrlAddressesExtracter::GetMediasAndTranscriptsUrlAddresses()
    {
        std::string medias_and_transcripts_url_addresses_file_line;
        std::ifstream medias_and_transcripts_url_addresses_file_stream(CurrentUnit().GetDownloadCentrePageFileName());

        if (!medias_and_transcripts_url_addresses_ptr_)
        {
            medias_and_transcripts_url_addresses_ptr_ = std::make_shared<MediasAndTranscriptsUrlAddresses>();
        }

        try
        {
            while (std::getline(medias_and_transcripts_url_addresses_file_stream, medias_and_transcripts_url_addresses_file_line))
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
                        medias_and_transcripts_url_addresses_ptr_->push_back(match[1].str());
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

    void DownloadCentrePageMediasAndTranscriptsUrlAddressesExtracter::CheckFilesExistenceOnFilesystem()
    {
        if(!medias_and_transcripts_url_addresses_ptr_)
        {
            return;
        }

        for(const auto& medias_and_transcripts_url_addresses_file_name : (*medias_and_transcripts_url_addresses_ptr_))
        {
            if (medias_and_transcripts_url_addresses_file_name.find(".mp4") != std::string::npos)
            {
                continue;
            }
            
            std::filesystem::path filesystem_file_name(DownloadFileNameToFilesystemFileName(medias_and_transcripts_url_addresses_file_name));

            if(!IsFilesystemFileExist(filesystem_file_name))
            {
                MissingFiles().SaveForDownload(medias_and_transcripts_url_addresses_file_name, filesystem_file_name);
            }
        }
    }

    std::string DownloadCentrePageMediasAndTranscriptsUrlAddressesExtracter::DownloadFileNameToFilesystemFileName(const std::string& download_file_name)
    {
        std::string filesystem_file_name(UrlAddressToDownloadFileName(download_file_name));

        DeleteRedundantSymbols(filesystem_file_name);

        AddCurrentUnitPrefix(filesystem_file_name);

        AddCurrentCoursePrefix(filesystem_file_name);

        return filesystem_file_name;
    }

    std::string DownloadCentrePageMediasAndTranscriptsUrlAddressesExtracter::UrlAddressToDownloadFileName(const std::string& url_address)
    {
        return url_address.substr(url_address.find_last_of('/') + 1);
    }

    bool DownloadCentrePageMediasAndTranscriptsUrlAddressesExtracter::IsFilesystemFileExist(std::filesystem::path& filesystem_file_name)
    {
        filesystem_file_name = *(CurrentCourse().GetCurrentCoursePath())
            / CurrentUnit().GetCurrentUnitSubDirectory() 
            / filesystem_file_name;

        return std::filesystem::exists(filesystem_file_name);
    }

    void DownloadCentrePageMediasAndTranscriptsUrlAddressesExtracter::DeleteRedundantSymbols(std::string& filesystem_file_name)
    {
        filesystem_file_name = std::regex_replace(filesystem_file_name, std::regex("^[b][^_]+_"), "_");

        filesystem_file_name = std::regex_replace(filesystem_file_name, std::regex("^\\d+_"), "_");

        filesystem_file_name = std::regex_replace(filesystem_file_name, std::regex("_download.*\\."), ".");

        filesystem_file_name = std::regex_replace(filesystem_file_name, std::regex("u\\d+_"), "_");

        filesystem_file_name = std::regex_replace(filesystem_file_name, std::regex("U\\d+_"), "_");

        filesystem_file_name = std::regex_replace(filesystem_file_name, std::regex("__"), "_");
    }

    void DownloadCentrePageMediasAndTranscriptsUrlAddressesExtracter::AddCurrentUnitPrefix(std::string& filesystem_file_name)
    {
        const size_t first_symbol_position = 0;
        const size_t symbols_number = 1;

        const unsigned int current_unit_number{CurrentUnit().GetCurrentUnitNumber()};

        if (filesystem_file_name[0] != '_')
        {
            filesystem_file_name.insert(first_symbol_position, symbols_number, '_');
        }

        if (current_unit_number < 10)
        {
            filesystem_file_name.insert(first_symbol_position, symbols_number, std::to_string(current_unit_number)[0]);
            filesystem_file_name.insert(first_symbol_position, symbols_number, '0');
        }
        else
        {
            filesystem_file_name.insert(first_symbol_position, symbols_number, std::to_string(current_unit_number)[1]);
            filesystem_file_name.insert(first_symbol_position, symbols_number, std::to_string(current_unit_number)[0]);
        }
        
        filesystem_file_name.insert(first_symbol_position, symbols_number, 'u');
    }

    void DownloadCentrePageMediasAndTranscriptsUrlAddressesExtracter::AddCurrentCoursePrefix(std::string& filesystem_file_name)
    {
        const size_t first_symbol_position = 0;
        const size_t symbols_number = 1;

        const unsigned int current_course_number{CurrentCourse().GetCurrentCourseIndex()};

        if (filesystem_file_name[0] != '_')
        {
            filesystem_file_name.insert(first_symbol_position, symbols_number, '_');
        }

        filesystem_file_name.insert(first_symbol_position, symbols_number, std::to_string(current_course_number)[0]);
        
        filesystem_file_name.insert(first_symbol_position, symbols_number, 'c');
    }
}