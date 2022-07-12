#include "currentUnitDownloadCentrePageDownloader.hpp"
#include "currentUnit.hpp"
#include "downloader.hpp"


namespace bbc_6_minute
{

    void CurrentUnitDownloadCentrePageDownloader::DownloadCurrentUnitDownloadCentrePage()
    {
        if (!std::filesystem::exists(current_unit_download_centre_page_file_name))
        {
            Downloader(GetUrlAddress()).Download();
        }
    }

    std::string CurrentUnitDownloadCentrePageDownloader::GetUrlAddress()
    {
        return CurrentUnit().GetCurrentUnitDownloadCentrePageUrlAddress();
    }

}