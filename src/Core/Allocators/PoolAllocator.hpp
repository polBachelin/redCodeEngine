/*
** Pol Bachelin, 2021
** redCodeEngine
** File description:
** PoolAllocator
*/

#ifndef POOLALLOCATOR_HPP_
#define POOLALLOCATOR_HPP_

#include "Allocator.hpp"

class PoolAllocator : public Allocator {
    public:
        PoolAllocator();
        ~PoolAllocator();

        void allocate(size_t s, uint8_t alignment = 8);
        void free(void *p);

    protected:
    private:
};

#endif /* !POOLALLOCATOR_HPP_ */
