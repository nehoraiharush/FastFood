#include "Timer.h"

Timer::Timer(double durationTime) : durationTime(durationTime), started(false), running(true), th([&]() {run(); }) {}

Timer::~Timer() {
    th.join();
}

bool Timer::isRunning() {
    return running;
}

double Timer::getTime()
{
    if (started)
        return currentTimeInMilliseconds() / 1000.0;
    else
        return 0;
}

void Timer::run() {
    start();
    while (durationTime > getTime());
    stop();
}

void Timer::start()
{
    startTime = system_clock::now();
    started = true;
    running = true;
}

void Timer::stop()
{
    endTime = system_clock::now();
    running = false;
}

double Timer::currentTimeInMilliseconds()
{
    time_point<system_clock> currentTime = system_clock::now();

    return duration_cast<milliseconds>(currentTime - startTime).count();
}