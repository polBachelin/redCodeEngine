/*
** EPITECH PROJECT, 2021
** redCodeEngine
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include "TypeID.hpp"
#include "Entity.hpp"

using ComponentTypeID = TypeID;
using ComponentID = TypeID;

class AComponent {
    public:
        AComponent() = default;
        ~AComponent() = default;

        const ComponentTypeID getComponentTypeID() const noexcept { return _componentTypeID; }
        const EntityID getOwner() { return _owner; }
        bool isActive() const { return _enabled;}
        void setActive(bool active) { _enabled = active; }

    protected:
        static const ComponentTypeID _componentTypeID;
        EntityID _owner;
        bool _enabled;
    private:
};

#endif /* !ACOMPONENT_HPP_ */
