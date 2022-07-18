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

    std::string CurrentCourse::GetCurrentCourseVocabularyReferenceUrlAddress(unsigned int current_unit_number)
    {
        return current_course_index_->url_addresses_begin_ 
            + std::to_string(current_unit_number) 
            + current_course_index_->vocabulary_reference_url_;
    }

    std::string CurrentCourse::GetCurrentCourseGrammarReferenceUrlAddress(unsigned int current_unit_number)
    {
        return current_course_index_->url_addresses_begin_ 
            + std::to_string(current_unit_number) 
            + current_course_index_->grammar_reference_url_;
    }

    const unsigned int CurrentCourse::GetMaximumUnitNumber()
    {
        return current_course_index_->maximum_units_number_;
    }

    unsigned int CurrentCourse::GetCurrentCourseIndex()
    {
        return static_cast<unsigned int>(std::distance(courses_.cbegin(), current_course_index_));
    }

    void CurrentCourse::AddCurrentCoursePrefix(std::string& filesystem_file_name)
    {
        const size_t first_symbol_position = 0;
        const size_t symbols_number = 1;

        const unsigned int current_course_number{CurrentCourse().GetCurrentCourseIndex()};

        if (filesystem_file_name[0] != '_')
        {
            filesystem_file_name.insert(first_symbol_position, symbols_number, '_');
        }

        filesystem_file_name.insert(first_symbol_position, symbols_number, std::to_string(current_course_number)[0]);
        
        filesystem_file_name.insert(first_symbol_position, symbols_number, 'c');
    }

    bool CurrentCourse::IsThereAnyCourse()
    {
        if (current_course_index_ == courses_.cend())
        {
            return false;
        }
        else
        {
            return true;
        }
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