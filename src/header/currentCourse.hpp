#pragma once

#include <memory>
#include <filesystem>
#include <vector>


namespace bbc_6_minute
{
    struct Course
    {
        std::string url_addresses_begin_;
        std::string url_address_end_;
        std::string part_of_vocabulary_reference_url_;
        std::string part_of_grammar_reference_url_;
        std::filesystem::path course_subdir_;
        unsigned int maximum_units_number_;
        unsigned int course_number_;
        bool is_need_for_download_;
    };
    

    class CurrentCourse
    {
    public:
        
        bool Go();
        std::shared_ptr<std::filesystem::path> GetCurrentCoursePath();
        std::string GetCurrentCourseDownloadCentrePageUrlAddress(unsigned int current_unit_number);
        std::string GetCurrentCourseVocabularyReferenceUrlAddress(unsigned int current_unit_number);
        std::string GetCurrentCourseGrammarReferenceUrlAddress(unsigned int current_unit_number);
        const unsigned int GetMaximumUnitNumber();
        unsigned int GetCurrentCourseNumber();
        void AddCurrentCoursePrefix(std::string& filesystem_file_name);

    private:
        bool IsCurrentCourseNeedForDownload();
        bool AreAllCoursesHaveEnded();
        void SkipCourseIndexNextIncrement();
        bool NextCourse();
    
    private:
        static std::vector<Course> courses_;
        static std::vector<Course>::const_iterator current_course_index_;
        const std::filesystem::path courses_path_{L"/home/dii/fdv/English/Bbc6minute/"};
        static bool skip_course_index_next_increment_;
    };
}