#pragma once


namespace bbc_6_minute
{
    class Pause
    {
    public:
        void On();

    private:
        unsigned int pause_duration_{10};
    };
}