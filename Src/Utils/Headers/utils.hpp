#pragma once

#include <memory>
#include <fstream>
#include <string>


namespace utils
{
    std::shared_ptr<std::ifstream> GetFileStream(const std::string& file_name);
}