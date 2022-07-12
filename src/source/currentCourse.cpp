#include "currentCourse.hpp"


namespace bbc_6_minute
{
    const std::array<std::string, static_cast<unsigned int>(CurrentCourseIndexes::course_number)> 
        courses_url_addresses_begin
        {"https://www.bbc.co.uk/learningenglish/english/course/lower-intermediate/unit-"
        , "https://www.bbc.co.uk/learningenglish/english/course/intermediate/unit-"
        , "https://www.bbc.co.uk/learningenglish/english/course/upper-intermediate/unit-"
        };
    
    const std::string url_address_end{"/downloads"};
    const std::filesystem::path courses_path{L"/home/dii/English/Bbc6minute/"};
    const std::array<std::filesystem::path, static_cast<unsigned int>(CurrentCourseIndexes::course_number)> 
        courses_subdirs {L"LowerIntermediate/", L"Intermediate/", L"UpperIntermediate/"};
    

    CurrentCourseIndexes CurrentCourse::current_course_index_ = CurrentCourseIndexes::start_service_value;

    std::shared_ptr<std::filesystem::path> CurrentCourse::GetCurrentCoursePath()
    {
        return std::make_shared<std::filesystem::path>(courses_path / courses_subdirs[static_cast<unsigned int>(current_course_index_)]);
    }
 /*   
    void CurrentCourse::GetCurrentCourseUrlAddress()
    {
    }
*/
    std::string CurrentCourse::GetCurrentCourseDownloadCentrePageUrlAddress(unsigned int current_unit_number)
    {
        return courses_url_addresses_begin[static_cast<unsigned int>(current_course_index_)] 
            + std::to_string(current_unit_number) 
            + url_address_end;
    }

    unsigned int CurrentCourse::GetCurrentCourseIndex()
    {
        return static_cast<unsigned int>(current_course_index_);
    }

    bool CurrentCourse::NextCourse()
    {
        if (current_course_index_ == CurrentCourseIndexes::start_service_value)
        {
            current_course_index_ = CurrentCourseIndexes::lower_intermediate;
        }
        else if (current_course_index_ == CurrentCourseIndexes::upper_intermediate)
        {
            return false;
        }
        else
        {
            current_course_index_ = static_cast<CurrentCourseIndexes>(
                static_cast<unsigned int>(current_course_index_) + 1
            );
        }
        
        return true;
    }
    
}