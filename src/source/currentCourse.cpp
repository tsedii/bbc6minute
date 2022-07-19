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
        , L"1LowerIntermediate/"
        , 30
        , 1
        , false
          }
        , {
          "https://www.bbc.co.uk/learningenglish/english/course/intermediate/unit-"
        , "/downloads"
        , "/tab/vocabulary"
        , "/tab/grammar"
        , L"2Intermediate/"
        , 30
        , 2
        , false
          }
        , {
          "https://www.bbc.co.uk/learningenglish/english/course/upper-intermediate/unit-"
        , "/downloads"
        , "/tab/vocabulary"
        , "/tab/grammar"
        , L"3UpperIntermediate/"
        , 30
        , 3
        , false
          }
        , {
          "https://www.bbc.co.uk/learningenglish/english/course/english-you-need/unit-"
        , "/downloads"
        , "/tab/vocabulary"
        , "/tab/grammar"
        , L"4EnglishYouNeed/"
        , 30
        , 4
        , false
          }
        , {
          "https://www.bbc.co.uk/learningenglish/english/course/shakespeare/unit-"
        , "/downloads"
        , "/tab/vocabulary"
        , "/tab/grammar"
        , L"5Shakespeare/"
        , 2
        , 5
        , false
          }
        , {
          "https://www.bbc.co.uk/learningenglish/english/course/newsreview/unit-"
        , "/downloads"
        , ""
        , ""
        , L"6Newsreview/"
        , 21
        , 6
        , true
          }
        , {
          "https://www.bbc.co.uk/learningenglish/english/features/6-minute-english"
        , "/"
        , ""
        , ""
        , L"7sixMinuteEnglish/"
        , 0
        , 7
        , false
          }
        };

    
    std::vector<Course>::const_iterator CurrentCourse::current_course_index_ = courses_.cbegin();

    bool CurrentCourse::skip_course_index_next_increment_{true};


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
        if (current_course_index_->part_of_vocabulary_reference_url_.empty())
        {
            return current_course_index_->part_of_vocabulary_reference_url_;
        }
        
        return current_course_index_->url_addresses_begin_ 
            + std::to_string(current_unit_number) 
            + current_course_index_->part_of_vocabulary_reference_url_;
    }

    std::string CurrentCourse::GetCurrentCourseGrammarReferenceUrlAddress(unsigned int current_unit_number)
    {
        if (current_course_index_->part_of_grammar_reference_url_.empty())
        {
            return current_course_index_->part_of_grammar_reference_url_;
        }

        return current_course_index_->url_addresses_begin_ 
            + std::to_string(current_unit_number) 
            + current_course_index_->part_of_grammar_reference_url_;
    }

    const unsigned int CurrentCourse::GetMaximumUnitNumber()
    {
        return current_course_index_->maximum_units_number_;
    }

    unsigned int CurrentCourse::GetCurrentCourseNumber()
    {
        return current_course_index_->course_number_;
    }

    void CurrentCourse::AddCurrentCoursePrefix(std::string& filesystem_file_name)
    {
        const size_t first_symbol_position = 0;
        const size_t symbols_number = 1;

        const unsigned int current_course_number{CurrentCourse().GetCurrentCourseNumber()};

        if (filesystem_file_name[0] != '_')
        {
            filesystem_file_name.insert(first_symbol_position, symbols_number, '_');
        }

        filesystem_file_name.insert(first_symbol_position, symbols_number, std::to_string(current_course_number)[0]);
        
        filesystem_file_name.insert(first_symbol_position, symbols_number, 'c');
    }

    bool CurrentCourse::IsCurrentCourseNeedForDownload()
    {
        if (AreAllCoursesHaveEnded())
        {
          return true;
        }
        
        if(current_course_index_->is_need_for_download_)
        {
            return true;
        }
        else
        {
            current_course_index_++;
            SkipCourseIndexNextIncrement();
            return false;
        }
    }

    bool CurrentCourse::AreAllCoursesHaveEnded()
    {
        return current_course_index_ == courses_.cend();
    }

    void CurrentCourse::SkipCourseIndexNextIncrement()
    {
        skip_course_index_next_increment_ = true;
    }

    bool CurrentCourse::NextCourse()
    {
        if (AreAllCoursesHaveEnded())
        {
            return false;
        }
        
        if (skip_course_index_next_increment_)
        {
           skip_course_index_next_increment_ = false;
        }
        else
        {
            current_course_index_++;
        }

        if (AreAllCoursesHaveEnded())
        {
            return false;
        }

        return true;
    }
    
    bool CurrentCourse::Go()
    {
        while (!IsCurrentCourseNeedForDownload())
        {}

        return NextCourse();
    }
}