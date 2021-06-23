/*
** Pol Bachelin
** redCodeEngine
** File description:
** Allocator
*/

#include "Allocator.hpp"

Allocator::Allocator(size_t size, void *start)
{
    _start = start;
    _size = size;
    _nbAllocs = 0;
    _memoryUsed = 0;
}

Allocator::~Allocator()
{}
