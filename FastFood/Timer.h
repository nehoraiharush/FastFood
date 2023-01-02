#pragma once
#include <thread>

using namespace std;
using namespace chrono;

class Timer
{
private:
    time_point<system_clock> startTime;
    time_point<system_clock> endTime;
    double durationTime;
    bool started;
    bool running;
    thread th;

public:
    Timer(double);
    ~Timer();
    bool isRunning();
    double getTime();
private:
    void run();
    void start();
    void stop();
    double currentTimeInMilliseconds();
};