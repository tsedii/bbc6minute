#include "currentUnit.hpp"
#include "currentCourse.hpp"
#include "missingFiles.hpp"


namespace bbc_6_minute
{
    unsigned int CurrentUnit::current_unit_number_ = 0;


    const std::string CurrentUnit::GetCurrentUnitDownloadCentrePageUrlAddress()
    {
        return CurrentCourse().GetCurrentCourseDownloadCentrePageUrlAddress(GetCurrentUnitNumber());
    }

    unsigned int CurrentUnit::GetCurrentUnitNumber()
    {
        return current_unit_number_;
    }

    const std::string CurrentUnit::GetCurrentUnitSubDirectory()
    {
        return std::string("Unit") 
            + ((current_unit_number_ < 10) ? std::string("0") + std::to_string(current_unit_number_) 
                : std::to_string(current_unit_number_)
            );
    }

    const std::string CurrentUnit::GetDownloadCentrePageFileName()
    {
        return current_unit_download_centre_page_file_name_;
    }

    bool CurrentUnit::NextCurrentUnit()
    {
        if ( current_unit_number_ == CurrentCourse().GetMaximumUnitNumber() )
        {
            current_unit_number_ = 0;

            return false;
        }
        
        ++current_unit_number_;

        return true;
    }

    bool CurrentUnit::Go()
    {
        if (std::filesystem::exists(current_unit_download_centre_page_file_name_))
        {
            std::filesystem::remove(current_unit_download_centre_page_file_name_);
        }

        if (MissingFiles().GetMissingFiles())
        {
            (MissingFiles().GetMissingFiles())->clear();
        }

        return CurrentUnit().NextCurrentUnit();
    }
}