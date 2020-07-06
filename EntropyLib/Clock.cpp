#include "Clock.h"

#include <Windows.h>

void Entropy::Timing::Clock::poll()
{
    timeLast = timeCurrent;
    QueryPerformanceCounter(&timeCurrent);
}

bool Entropy::Timing::Clock::initialize()
{
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&timeCurrent);
    timeLast = timeCurrent;
    return true;
}

bool Entropy::Timing::Clock::shutdown()
{
    return true;
}

float Entropy::Timing::Clock::timeElapsed() const
{
    LARGE_INTEGER delta;
    delta.QuadPart = timeCurrent.QuadPart - timeLast.QuadPart;
    float deltaTime = ((float)delta.QuadPart) / frequency.QuadPart;
    return deltaTime;
}
