/*
** Pol Bachelin 2021
** redCodeEngine
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include "AComponent.hpp"

template<class T>
class Component : public AComponent {
    public:
        Component() {};
        ~Component() {};

        ComponentTypeID getStaticComponentTypeID() const 
        {
            return _componentTypeID;
        }
        static const ComponentTypeID _componentTypeID;
};

//This forces the compiler to create an instance of Component T in order to set its unique identifier
template<class T>
const ComponentTypeID Component<T>::_componentTypeID = TypeIDCounter<AComponent>::get<T>();

#endif /* !COMPONENT_HPP_ */
