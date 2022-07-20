#pragma once

#include <string>
#include <filesystem>


namespace bbc_6_minute
{

    class CurrentUnitDownloadCentrePageDownloader
    {
    public:
        void DownloadCurrentUnitDownloadCentrePage();

    private:
        std::string GetUrlAddress();
        std::string GetCurrentUnitDownloadCentrePageUrlAddress();
    };

}