#include "currentUnitDownloadCentrePageDownloader.hpp"
#include "currentUnit.hpp"
#include "downloader.hpp"


namespace bbc_6_minute
{

    void CurrentUnitDownloadCentrePageDownloader::DownloadCurrentUnitDownloadCentrePage()
    {
        if (!std::filesystem::exists(CurrentUnit().GetDownloadCentrePageFileName()))
        {
            Downloader(GetUrlAddress()).Download();
        }
    }

    std::string CurrentUnitDownloadCentrePageDownloader::GetUrlAddress()
    {
        return CurrentUnit().GetCurrentUnitDownloadCentrePageUrlAddress();
    }

}