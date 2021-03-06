#pragma once

#include <vector>
#include <memory>


namespace bbc_6_minute
{
    namespace with_units_courses
    {
        typedef std::vector<std::string> MediasAndTranscriptsUrlAddresses;

        class DownloadCentrePageMediasAndTranscriptsUrlAddressesExtracter
        {
        
        public:
            void ExtractDownloadCentrePageMediasAndTranscriptsUrlAddresses();
    
        private:
            void GetMediasAndTranscriptsUrlAddresses();
    
            void DownloadCurrentUnitMediasAndTranscriptsUrlAddresses();
    
            void CheckFilesExistenceOnFilesystem();
    
            std::string DownloadFileNameToFilesystemFileName(const std::string& download_file_name);
    
            void DeleteRedundantSymbols(std::string& filesystem_file_name);
    
        private:
            std::shared_ptr<MediasAndTranscriptsUrlAddresses> medias_and_transcripts_url_addresses_ptr_{nullptr};
            const std::vector<std::string> string_extract_file_name_templates_{
                {"[^<]*<a href=\"([^\"]*)\">Download"}
                , {"[^<]*<a class=\"download\" href=\"([^\"]*)\">"}
            };
        };
    }
}