/*
** EPITECH PROJECT, 2021
** redCodeEngine
** File description:
** IComponentPool
*/

#ifndef ICOMPONENTPOOL_HPP_
#define ICOMPONENTPOOL_HPP_

#include "AComponent.hpp"

class IComponentPool {
    public:
        virtual ~IComponentPool() {};

        virtual void destroyComponent(AComponent *) = 0;
        virtual const char *getTypeName() const = 0;
};

#endif /* !ICOMPONENTPOOL_HPP_ */
