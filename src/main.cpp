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

    std::string GetWgetCommandLine()
    {
        return std::string("wget ") + CurrentUnitPageUrlAddress().GetUrlAddress();
    }

}


int main()
{
    std::system(bbc_6_minute::GetWgetCommandLine().c_str());
}