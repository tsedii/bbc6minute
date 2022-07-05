#pragma once

#include "common.h"


namespace bbc_6_minute
{

    class CurrentUnitPageUrlAddress
    {
    public:
        std::string GetUrlAddress();
    
    private:
        unsigned int GetUnitNumber();
    
    private:
        static unsigned int download_page_number_;
    };

}