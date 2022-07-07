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
        /*
        std::filesystem::remove(current_unit_download_centre_page_file_name);

        CurrentUnit().NextCurrentUnit();
        */
    }

    std::string CurrentUnitDownloadCentrePageDownloader::GetUrlAddress()
    {
        return std::string(lower_intermediate_course_url_address_begin 
            + std::to_string(CurrentUnit().GetCurrentUnitNumber())
            + url_address_end
        );
    }

}