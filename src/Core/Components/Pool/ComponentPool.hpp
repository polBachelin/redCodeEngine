/*
** Pol Bachelin, 2021
** redCodeEngine
** File description:
** ComponentPool
*/

#ifndef COMPONENTPOOL_HPP_
#define COMPONENTPOOL_HPP_

#include "IComponentPool.hpp"
#include <list>
#include "loguru/loguru.hpp"

template<class T>
class ComponentPool : public IComponentPool {
    public:
        ComponentPool() {
            LOG_F(INFO, "Creating Entity Pool");
        }
        virtual ~ComponentPool() {};

    protected:
    private:
};

#endif /* !COMPONENTPOOL_HPP_ */
