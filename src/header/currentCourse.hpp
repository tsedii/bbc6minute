#pragma once

#include <memory>
#include <filesystem>


namespace bbc_6_minute
{
    enum class CurrentCourseIndexes {
            lower_intermediate, intermediate, upper_intermediate, course_number, start_service_value
    };

    class CurrentCourse
    {
        
    public:
        
        std::shared_ptr<std::filesystem::path> GetCurrentCoursePath();
        //void GetCurrentCourseUrlAddress();
        std::string GetCurrentCourseDownloadCentrePageUrlAddress(unsigned int current_unit_number);
        unsigned int GetCurrentCourseIndex();
        bool NextCourse();
    
    private:
        static CurrentCourseIndexes current_course_index_;
    };
}