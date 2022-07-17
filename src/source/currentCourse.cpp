#include "currentCourse.hpp"

#include <iterator>


namespace bbc_6_minute
{
    std::vector<Course> CurrentCourse::courses_ = 
        { 
          {
           "https://www.bbc.co.uk/learningenglish/english/course/lower-intermediate/unit-"
        , "/downloads"
        , "/tab/vocabulary"
        , "/tab/grammar"
        , L"LowerIntermediate/"
        , 30
          }
        , {
           "https://www.bbc.co.uk/learningenglish/english/course/intermediate/unit-"
        , "/downloads"
        , "/tab/vocabulary"
        , "/tab/grammar"
        , L"Intermediate/"
        , 30
          }
        , {
           "https://www.bbc.co.uk/learningenglish/english/course/upper-intermediate/unit-"
        , "/downloads"
        , "/tab/vocabulary"
        , "/tab/grammar"
        , L"UpperIntermediate/"
        , 30
          }
        };

    std::vector<Course>::const_iterator CurrentCourse::current_course_index_ = --(courses_.cbegin());

    bool CurrentCourse::Go()
    {
        return NextCourse();
    }

    std::shared_ptr<std::filesystem::path> CurrentCourse::GetCurrentCoursePath()
    {
        return std::make_shared<std::filesystem::path>(courses_path_ / current_course_index_->course_subdir_);
    }

    std::string CurrentCourse::GetCurrentCourseDownloadCentrePageUrlAddress(unsigned int current_unit_number)
    {
        return current_course_index_->url_addresses_begin_ 
            + std::to_string(current_unit_number) 
            + current_course_index_->url_address_end_;
    }

    const unsigned int CurrentCourse::GetMaximumUnitNumber()
    {
        return current_course_index_->maximum_units_number_;
    }

    unsigned int CurrentCourse::GetCurrentCourseIndex()
    {
        return static_cast<unsigned int>(std::distance(courses_.cbegin(), current_course_index_));
    }

    bool CurrentCourse::NextCourse()
    {
        if (current_course_index_ == courses_.cend())
        {
            return false;
        }

        current_course_index_++;
        
        return true;
    }
    
}