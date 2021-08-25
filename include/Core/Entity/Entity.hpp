/*
** Pol BACHELIN, 2021
** redCodeEngine
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include "AEntity.hpp"

template<class T>
class Entity : public AEntity {

    //void operator delete(void *) = delete;
    //void operator delete[](void *) = delete;
    public:
        Entity() {};
        ~Entity() {};

        EntityTypeID getEntityTypeID() const { return _entityTypeID; }
        static const EntityTypeID _entityTypeID;
    private:
};

template<class T>
const EntityTypeID Entity<T>::_entityTypeID = TypeIDCounter<AEntity>::get<T>();

#endif /* !AENTITY_HPP_ */
