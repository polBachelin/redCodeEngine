/*
** EPITECH PROJECT, 2021
** redCodeEngine
** File description:
** ObjectPool
*/

#ifndef OBJECTPOOL_HPP_
#define OBJECTPOOL_HPP_

#include <cstddef>
#include <iostream>
#include <list>
#include "loguru/loguru.hpp"

template<class Object, size_t MAX_OBJECTS>
class ObjectPool {
    public:
        ObjectPool() {
            LOG_F(INFO, "Creating Object Pool");
        }
        ~ObjectPool();

        Object *createObject() {
            Object *obj = new Object();

            _objects.push_back(obj);
            return obj;
        }

    protected:
        std::list<Object *> _objects;
    private:
};

#endif /* !OBJECTPOOL_HPP_ */
