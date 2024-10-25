#include "timer.h"

void Timer::Reset(){
    this->start = chrono::high_resolution_clock::now();
}

void Timer::CurrentTime(){
    this->end = chrono::high_resolution_clock::now();
    double elapsed_micros = chrono::duration<double, micro>(end - start).count();
    cout << "CPU time: " << elapsed_micros << " microseconds";
}

Timer::Timer(){}