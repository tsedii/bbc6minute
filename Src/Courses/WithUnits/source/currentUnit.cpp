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

    void CurrentUnit::AddCurrentUnitPrefix(std::string& filesystem_file_name)
    {
        const size_t first_symbol_position = 0;
        const size_t symbols_number = 1;

        const unsigned int current_unit_number{CurrentUnit().GetCurrentUnitNumber()};

        if (filesystem_file_name[0] != '_')
        {
            filesystem_file_name.insert(first_symbol_position, symbols_number, '_');
        }

        if (current_unit_number < 10)
        {
            filesystem_file_name.insert(first_symbol_position, symbols_number, std::to_string(current_unit_number)[0]);
            filesystem_file_name.insert(first_symbol_position, symbols_number, '0');
        }
        else
        {
            filesystem_file_name.insert(first_symbol_position, symbols_number, std::to_string(current_unit_number)[1]);
            filesystem_file_name.insert(first_symbol_position, symbols_number, std::to_string(current_unit_number)[0]);
        }
        
        filesystem_file_name.insert(first_symbol_position, symbols_number, 'u');
    }

    std::shared_ptr<std::filesystem::path> CurrentUnit::GetFullFilesystemFileName(const std::filesystem::path& filesystem_file_name)
    {
        return std::make_shared<std::filesystem::path>(
            *(CurrentCourse().GetCurrentCoursePath())
            / CurrentUnit().GetCurrentUnitSubDirectory() 
            / filesystem_file_name
        );
    }

    bool CurrentUnit::IsFilesystemFileExist(const std::filesystem::path& filesystem_file_name)
    {
        return std::filesystem::exists(filesystem_file_name);
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
        if (!CurrentCourse().IsThisCourseWithUnits())
        {
            return false;
        }
        
        if (std::filesystem::exists(current_unit_download_centre_page_file_name_))
        {
            std::filesystem::remove(current_unit_download_centre_page_file_name_);
        }

        if (MissingFiles().GetMissingFiles())
        {
            (MissingFiles().GetMissingFiles())->clear();
        }

        return NextCurrentUnit();
    }
}