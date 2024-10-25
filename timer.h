#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <chrono>
using namespace std;

class Timer{
    private: 
        chrono::high_resolution_clock::time_point start;
        chrono::high_resolution_clock::time_point end;
    public:
        Timer();
        void Reset();
        void CurrentTime();
};

#endif