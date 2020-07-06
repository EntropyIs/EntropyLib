#include "Clock.h"

#include <Windows.h>

void Entropy::Timing::Clock::poll()
{
    timeLast = timeCurrent;
    QueryPerformanceCounter(&timeCurrent);

    LARGE_INTEGER delta;
    delta.QuadPart = timeCurrent.QuadPart - timeLast.QuadPart;

    deltaTime = ((float)delta.QuadPart) / frequency.QuadPart;
}

bool Entropy::Timing::Clock::initialize()
{
    bool b = QueryPerformanceFrequency(&frequency);
    if (!b)
        return false;
    b = QueryPerformanceCounter(&timeLast);
    timeCurrent = timeLast;
    deltaTime = 0.0f;
    return b;
}

bool Entropy::Timing::Clock::shutdown()
{
    return true;
}

float Entropy::Timing::Clock::timeElapsed() const
{
    return deltaTime;
}
