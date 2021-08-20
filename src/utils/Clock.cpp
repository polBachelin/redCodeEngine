/*
** EPITECH PROJECT, 2021
** redCodeEngine
** File description:
** Clock
*/

#include "Clock.hpp"

Clock::Clock()
{
    this->restart();
}

Clock::~Clock()
{
}

double Clock::getElapsedTime() const
{
    std::chrono::high_resolution_clock::time_point time = std::chrono::high_resolution_clock::now();
    int elapsed = std::chrono::duration_cast<std::chrono::microseconds>(time - _begin).count();
    double seconds = elapsed / 1000000;

    return seconds;

}

void Clock::restart()
{
    _begin = std::chrono::high_resolution_clock::now();
}