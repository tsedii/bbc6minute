#pragma once

#include <vector>
#include <string>
#include <filesystem>


namespace bbc_6_minute
{
    enum class CourseNumber {
        lower_intermediate = 1, intermediate, upper_intermediate
    };

    const CourseNumber course_number = CourseNumber::lower_intermediate;

    typedef std::vector<std::string> MediasAndTranscriptsUrlAddresses;

    const std::string lower_intermediate_course_url_address_begin{"https://www.bbc.co.uk/learningenglish/english/course/lower-intermediate/unit-"};
    const std::string url_address_end{"/downloads"};

    const std::filesystem::path lower_intermediate_course_path{L"/home/dii/English/lowerIntermediate"};

    const std::string medias_and_transcripts_url_addresses_file_name{"downloads"};

    const std::string string_extract_file_name_template{"[^<]*<a href=\"([^\"]*)\">Download"};
}