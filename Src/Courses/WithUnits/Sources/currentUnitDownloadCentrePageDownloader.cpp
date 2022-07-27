#include "currentUnitDownloadCentrePageDownloader.hpp"
#include "currentUnit.hpp"
#include "downloader.hpp"
#include "utils.hpp"


namespace bbc_6_minute
{
    namespace with_units_courses
    {
        void CurrentUnitDownloadCentrePageDownloader::DownloadCurrentUnitDownloadCentrePage()
        {
            if (!utils::filesystem::IsFilesystemObjectExists(CurrentUnit().GetDownloadCentrePageFileName()))
            {
                utils::Downloader(GetUrlAddress()).Download();
            }
        }

        std::string CurrentUnitDownloadCentrePageDownloader::GetUrlAddress()
        {
            return CurrentUnit().GetCurrentUnitDownloadCentrePageUrlAddress();
        }
    }
}