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
        AComponent() {};
        virtual ~AComponent() {};

        ComponentTypeID getComponentTypeID() const noexcept { return _componentTypeID; }
        EntityID getOwner() { return _owner; }
        void setOwner(const EntityID &id) { _owner = id; }
        bool isActive() const { return _enabled;}
        void setActive(bool active) { _enabled = active; }

    protected:
        static const ComponentTypeID _componentTypeID;
        EntityID _owner;
        bool _enabled;
    private:
};
#endif /* !ACOMPONENT_HPP_ */
