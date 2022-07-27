#pragma once


namespace utils
{
    class Pause
    {
    public:
        void On();

    private:
        unsigned int pause_duration_{10};
    };
}