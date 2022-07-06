#pragma once

#include <vector>
#include <map>
#include <string>
#include <filesystem>


namespace bbc_6_minute
{
    enum class CurrentCourse {
        lower_intermediate, intermediate, upper_intermediate, course_number
    };

    const CurrentCourse current_course = CurrentCourse::lower_intermediate;

    typedef std::vector<std::string> MediasAndTranscriptsUrlAddresses;

    typedef std::map<std::string, std::filesystem::path> MissingFilesForDownload;

    const std::string lower_intermediate_course_url_address_begin{
        "https://www.bbc.co.uk/learningenglish/english/course/lower-intermediate/unit-"
    };

    const std::string url_address_end{"/downloads"};

    const std::filesystem::path courses_path{L"/home/dii/English/Bbc6minute/"};

    const std::array<std::string, static_cast<unsigned int>(CurrentCourse::course_number)> 
        courses_subdirs {"LowerIntermediate", "Intermediate", "UpperIntermediate"};

    const std::string current_unit_download_centre_page_file_name{"downloads"};

    const std::string string_extract_file_name_template{"[^<]*<a href=\"([^\"]*)\">Download"};
}