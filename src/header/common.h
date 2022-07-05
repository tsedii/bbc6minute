#pragma once

#include <string>
#include <filesystem>


namespace bbc_6_minute
{
    const std::string lower_intermediate_course_url_address_begin{"https://www.bbc.co.uk/learningenglish/english/course/lower-intermediate/unit-"};
    const std::string url_address_end{"/downloads"};

    const std::filesystem::path lower_intermediate_course_path{L"/home/dii/English/lowerIntermediate"};

    const std::string downloads_file_name{"downloads"};

    const std::string string_extract_file_name_template{"[^<]*<a href=\"([^\"]*)\">Download"};
}