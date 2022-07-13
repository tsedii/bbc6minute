#pragma once

#include <string>


namespace bbc_6_minute
{
    class CurrentUnit
    {
    public:
        const std::string GetCurrentUnitDownloadCentrePageUrlAddress();
        const std::string GetCurrentUnitSubDirectory();
        const std::string GetDownloadCentrePageFileName();
        bool Go();

    private:
        unsigned int GetCurrentUnitNumber();
        bool NextCurrentUnit();

    private:
        static unsigned int current_unit_number_;
        const std::string current_unit_download_centre_page_file_name_{"downloads"};
    };
}