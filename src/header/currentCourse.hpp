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
        std::string vocabulary_reference_url_;
        std::string grammar_reference_url_;
        std::filesystem::path course_subdir_;
        unsigned int maximum_units_number_;
    };
    

    class CurrentCourse
    {
    public:
        
        bool Go();
        std::shared_ptr<std::filesystem::path> GetCurrentCoursePath();
        std::string GetCurrentCourseDownloadCentrePageUrlAddress(unsigned int current_unit_number);
        const unsigned int GetMaximumUnitNumber();
        unsigned int GetCurrentCourseIndex();
        bool NextCourse();
    
    private:
        static std::vector<Course> courses_;
        static std::vector<Course>::const_iterator current_course_index_;
        const std::filesystem::path courses_path_{L"/home/dii/fdv/English/Bbc6minute/"};
    };
}