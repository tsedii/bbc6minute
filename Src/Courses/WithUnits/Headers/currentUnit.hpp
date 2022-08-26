#pragma once

#include <string>
#include <filesystem>


namespace bbc_6_minute
{
    namespace with_units_courses
    {
        class CurrentUnit
        {
        public:
            const std::string GetCurrentUnitDownloadCentrePageUrlAddress();
            const std::string GetCurrentUnitSubDirectory();
            const std::string GetDownloadCentrePageFileName();
            bool Go();
            unsigned int GetCurrentUnitNumber();
            void AddCurrentUnitPrefix(std::string& filesystem_file_name);
            std::shared_ptr<std::filesystem::path> GetFullFilesystemFileName(const std::filesystem::path& filesystem_file_name);
            void DownloadCourseWithUnits();
    
        private:
            bool NextCurrentUnit();
    
        private:
            static unsigned int current_unit_number_;
            const std::string current_unit_download_centre_page_file_name_{"downloads"};
        };
    }
}