#include "pause.hpp"

#include <thread>
#include <chrono>


namespace bbc_6_minute
{
    void Pause::On()
    {
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }
}