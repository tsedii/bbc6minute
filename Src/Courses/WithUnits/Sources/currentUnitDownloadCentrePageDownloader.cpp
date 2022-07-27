#include "currentUnitDownloadCentrePageDownloader.hpp"
#include "currentUnit.hpp"
#include "downloader.hpp"
#include "utils.hpp"


namespace bbc_6_minute
{

    void CurrentUnitDownloadCentrePageDownloader::DownloadCurrentUnitDownloadCentrePage()
    {
        if (!utils::IsFilesystemObjectExists(CurrentUnit().GetDownloadCentrePageFileName()))
        {
            Downloader(GetUrlAddress()).Download();
        }
    }

    std::string CurrentUnitDownloadCentrePageDownloader::GetUrlAddress()
    {
        return CurrentUnit().GetCurrentUnitDownloadCentrePageUrlAddress();
    }

}