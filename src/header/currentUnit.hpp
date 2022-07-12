#pragma once

#include <string>


namespace bbc_6_minute
{
    const std::string current_unit_download_centre_page_file_name{"downloads"};

    const unsigned int maximum_unit_number = 30;

    class CurrentUnit
    {
    public:
        std::string GetCurrentUnitDownloadCentrePageUrlAddress();
        std::string GetCurrentUnitSubDirectory();
        bool Go();

    private:
        unsigned int GetCurrentUnitNumber();
        bool NextCurrentUnit();

    private:
        static unsigned int current_unit_number_;
    };
}