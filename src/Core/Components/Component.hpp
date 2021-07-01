/*
** Pol Bachelin 2021
** redCodeEngine
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include "TypeID.hpp"

using ComponentTypeID = TypeID;

template<class T>
class Component {
    public:
        Component() = default;
        ~Component() = default;

        const ComponentTypeID getComponentTypeID() const noexcept { return _componentTypeID; }
    protected:
        static const ComponentTypeID _componentTypeID;
};

#endif /* !COMPONENT_HPP_ */
