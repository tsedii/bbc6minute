#pragma once

#include "common.hpp"


namespace bbc_6_minute
{

    class CurrentUnitDownloadCentrePageDownloader
    {
    public:
        void DownloadCurrentUnitDownloadCentrePage();

    private:
        std::string GetUrlAddress();
        std::string GetWgetCommandLine();
        std::string GetCurrentUnitDownloadCentrePageUrlAddress();
    };

}