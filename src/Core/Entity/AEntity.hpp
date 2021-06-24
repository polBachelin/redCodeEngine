/*
** EPITECH PROJECT, 2021
** redCodeEngine
** File description:
** AEntity
*/

#ifndef AENTITY_HPP_
#define AENTITY_HPP_

#include "TypeID.hpp"

using EntityTypeID = size_t;
using EntityID = size_t;

class AEntity {
    public:
        AEntity();
        ~AEntity();

        virtual const EntityTypeID getEntityTypeID() const = 0;
        const EntityID getEntityID() const { return _id; }
        void setEnable(bool enable) { _enabled = enable; }
        bool getEnable() const { return _enabled; }

    private:
        bool _enabled;
        EntityID _id;
};

#endif /* !AENTITY_HPP_ */
