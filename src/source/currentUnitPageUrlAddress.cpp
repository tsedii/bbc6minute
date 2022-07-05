#include "currentUnitPageUrlAddress.hpp"


namespace bbc_6_minute
{

    unsigned int CurrentUnitPageUrlAddress::download_page_number_ = 1;

    std::string CurrentUnitPageUrlAddress::GetUrlAddress()
    {
        return std::string(lower_intermediate_course_url_address_begin 
            + std::to_string(GetUnitNumber())
            + url_address_end
        );
    }
    
    unsigned int CurrentUnitPageUrlAddress::GetUnitNumber()
    {
        return download_page_number_++;
    }

}