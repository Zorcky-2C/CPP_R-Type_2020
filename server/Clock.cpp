/*
** EPITECH PROJECT, 2020
** B_CPP_501_BDX_5_1_rtype_philippe_jacques_tatel
** File description:
** TODO: add description
*/
#include "Clock.hpp"

void Clock::Start()
{
    _start = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now());
}

void Clock::End()
{
    _end = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now());
}

void Clock::Wait()
{
    std::chrono::microseconds time_span(_end - _start);

    while (time_span.count() < 100000) {
        End();
        time_span = _end - _start;
    }
}
