/*
** EPITECH PROJECT, 2020
** B_CPP_501_BDX_5_1_rtype_philippe_jacques_tatel
** File description:
** TODO: add description
*/

#ifndef B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_CLOCK_HPP
#define B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_CLOCK_HPP

#include <chrono>

class Clock
{
    public:
        void Start();
        void End();
        void Wait();
    private:
        std::chrono::time_point<std::chrono::system_clock, std::chrono::microseconds> _start;
        std::chrono::time_point<std::chrono::system_clock, std::chrono::microseconds> _end;
};

#endif //B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_CLOCK_HPP
