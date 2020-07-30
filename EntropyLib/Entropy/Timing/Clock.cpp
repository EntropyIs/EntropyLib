#include "Clock.h"

#include<GLFW/glfw3.h>

void Entropy::Timing::Clock::poll()
{
    float timeCurrent = (float)glfwGetTime();
    deltaTime = timeCurrent - lastTime;
    lastTime = timeCurrent;
}

bool Entropy::Timing::Clock::initialize()
{
    deltaTime = 0.0f;
    lastTime = 0.0f;
    return true;
}

bool Entropy::Timing::Clock::shutdown()
{
    return true;
}

float Entropy::Timing::Clock::timeElapsed() const
{
    return deltaTime;
}
