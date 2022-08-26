#include "utils.hpp"

#include <iostream>
#include <regex>

#include "logger.hpp"


namespace utils
{
    namespace filesystem
    {
        std::shared_ptr<std::fstream> GetFileStream ( const std::string& file_name, std::ios_base::openmode mode )
        {
            std::shared_ptr<std::fstream> file_stream_ptr(
                std::make_shared<std::fstream> ( file_name, mode )
            );

            if ( !file_stream_ptr )
            {
                throw std::logic_error (
                    FOR_LOG_LINE_FUNC_FILE (
                        std::string ( "\n can't create std::shared_ptr for std::fstream for open " )
                        + file_name
                    )
                );
            }
            else if ( !file_stream_ptr->is_open() )
            {
                throw std::logic_error ( 
                    FOR_LOG_LINE_FUNC_FILE ( std::string( "\n failed to open " ) + file_name )
                );
            }

            return file_stream_ptr;
        }
    
        void CreateMissingSubdirectories(const std::filesystem::path& missing_filesystem_object)
        {
            std::filesystem::path missing_filesystem_object_tmp(missing_filesystem_object);
    
            if (std::filesystem::is_regular_file(missing_filesystem_object_tmp))
            {
                missing_filesystem_object_tmp = missing_filesystem_object_tmp.remove_filename();
            }
            
            if (!IsFilesystemObjectExists(missing_filesystem_object_tmp))
            {
                std::filesystem::create_directories(missing_filesystem_object_tmp);
            }
        }
    
        bool RemoveFile(const std::filesystem::path& file_name)
        {
            try
            {
                if (std::filesystem::exists(file_name))
                {
                    std::filesystem::remove(file_name);
                }
            }
            catch(const std::exception& e)
            {
                std::stringstream error_string_stream;
                error_string_stream << std::endl << e.what() << std::endl;
                throw std::runtime_error ( FOR_LOG_LINE_FUNC_FILE ( error_string_stream.str ( ) ) );
            }
            catch(...)
            {
                throw std::runtime_error ( FOR_LOG_LINE_FUNC_FILE ( std::string ( "\n Unknown error \n" ) ) );
            }
    
            return true;       
        }
    
        bool IsFilesystemObjectExists(const std::filesystem::path& filesystem_object)
        {
            return std::filesystem::exists(filesystem_object);
        }

        std::shared_ptr<std::string> UrlAddressToDownloadFileName(const std::string& url_address)
        {
            return std::make_shared<std::string>(
                url_address.substr(url_address.find_last_of('/') + 1)
            );
        }
    }

    namespace string
    {
        std::shared_ptr<std::string> SingleExtractSubstringFromString(
            const std::string& string
            , const std::string& substring_regex_template
        )
        {
            // substring_regex_template example: "/(\\d{6})_" 
            // It extracts only six digits from string like "dfk123vhbekb/123456_d;fgb;rg;rnb"
            std::regex regex_extract_date_template(substring_regex_template);

            std::smatch match;

            if (std::regex_search(
                string.cbegin()
                , string.cend()
                , match
                , regex_extract_date_template
            ))
            {
                return std::make_shared<std::string>(match[1].str());
            }

            return nullptr;
        }
    }

    namespace date
    {
        std::shared_ptr<std::string> DdMmYyyyDateToYyMmDd(const std::string& dd_mm_yyyy_date)
        {
            // 20102014 to 141020 or DDmmYYYY to YYmmDD

            if ( dd_mm_yyyy_date.size() < std::string("20102014").size() )
            {
                throw std::runtime_error ( FOR_LOG_LINE_FUNC_FILE ( std::string ( "\n Error input date format \n" ) ) );
            }

            std::string yy_mm_dd_date = dd_mm_yyyy_date.substr(0, 2);

            yy_mm_dd_date.insert(0, dd_mm_yyyy_date.substr(2, 2));

            yy_mm_dd_date.insert(0, dd_mm_yyyy_date.substr(6));

            return std::make_shared<std::string>(yy_mm_dd_date);
        }
    }
}
