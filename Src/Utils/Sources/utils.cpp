#include "utils.hpp"

#include <iostream>


namespace utils
{
    std::shared_ptr<std::ifstream> GetFileStream(const std::string& file_name)
    {
        std::shared_ptr<std::ifstream> file_stream_ptr;

        try
        {
            file_stream_ptr = std::make_shared<std::ifstream>(file_name);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return nullptr;
        }
        catch(...)
        {
            return nullptr;
        }
        
        return file_stream_ptr;
    }
}