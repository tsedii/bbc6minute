#include "currentUnitDownloadCentrePageDownloader.hpp"
#include "currentUnit.hpp"


namespace bbc_6_minute
{

    std::string CurrentUnitDownloadCentrePageDownloader::GetWgetCommandLine()
    {
        return std::string("wget ") + GetUrlAddress();
    }

    void CurrentUnitDownloadCentrePageDownloader::DownloadCurrentUnitDownloadCentrePage()
    {
        if (!std::filesystem::exists(bbc_6_minute::current_unit_download_centre_page_file_name))
        {
            std::system(GetWgetCommandLine().c_str());
        }
    }

    std::string CurrentUnitDownloadCentrePageDownloader::GetUrlAddress()
    {
        return std::string(lower_intermediate_course_url_address_begin 
            + std::to_string(CurrentUnit().GetCurrentUnitNumber())
            + url_address_end
        );
    }

}