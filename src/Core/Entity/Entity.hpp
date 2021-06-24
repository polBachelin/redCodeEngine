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

    void operator delete(void *) = delete;
    void operator delete[](void *) = delete;
    public:
        Entity() {};
        ~Entity() {};

        static const EntityTypeID STATIC_ENTITY_TYPE_ID;

        const EntityTypeID getEntityTypeID() const { return STATIC_ENTITY_TYPE_ID; }

    private:
};

template<class T>
const EntityTypeID Entity<T>::STATIC_ENTITY_TYPE_ID = TypeID::get();

#endif /* !AENTITY_HPP_ */
