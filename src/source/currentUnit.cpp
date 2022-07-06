#include "currentUnit.hpp"


namespace bbc_6_minute
{
    unsigned int CurrentUnit::current_unit_number_ = 1;

    unsigned int CurrentUnit::GetCurrentUnitNumber()
    {
        return current_unit_number_;
    }

    std::string CurrentUnit::GetCurrentUnitSubDirectory()
    {
        return std::string("Unit") 
            + ((current_unit_number_ < 10) ? std::string("0") + std::to_string(current_unit_number_) 
            : std::to_string(current_unit_number_));
    }

    void CurrentUnit::NextCurrentUnit()
    {
        ++current_unit_number_;
    }
}