#pragma once

#include <string>


namespace bbc_6_minute
{
    class CurrentUnit
    {
    public:
        unsigned int GetCurrentUnitNumber();
        std::string GetCurrentUnitSubDirectory();
        void NextCurrentUnit();

    private:
        static unsigned int current_unit_number_;
    };
}