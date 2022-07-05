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

    void GetFilesUrlAddressesForDownload()
    {
        std::string downloads_file_line;
        std::ifstream downloads_file_stream(bbc_6_minute::downloads_file_name);

        std::regex regex_extract_file_name_template(bbc_6_minute::string_extract_file_name_template);

        try
        {
            while (std::getline(downloads_file_stream, downloads_file_line))
            {
                if (!(downloads_file_line.find(".pdf") != std::string::npos or downloads_file_line.find(".mp3") != std::string::npos))
                {
                    continue;
                }

                /*
                std::regex_search cause Segmentation fault when trying to process too big std::string().size() = 269553
                
                std::cout << downloads_file_line.size() << std::endl;
                */

                std::smatch match;

                std::string::const_iterator search_start( downloads_file_line.cbegin() );

                while (std::regex_search(search_start, downloads_file_line.cend(), match, regex_extract_file_name_template))
                {
                    std::cout << match[1] << std::endl;
                    search_start = match.suffix().first;
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

    void CheckFileExistenceOnFilesystem()
    {}

}