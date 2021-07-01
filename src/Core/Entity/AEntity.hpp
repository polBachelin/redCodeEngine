/*
** EPITECH PROJECT, 2021
** redCodeEngine
** File description:
** AEntity
*/

#ifndef AENTITY_HPP_
#define AENTITY_HPP_

#include "TypeID.hpp"
#include <cstdint>

using EntityTypeID = TypeID;
using EntityID = TypeID;

class AEntity {
    public:
        AEntity() {};
        ~AEntity() {};

        virtual EntityTypeID getEntityTypeID() const = 0;
        EntityID getEntityID() const { return _id; }
        void setEnable(bool enable) { _enabled = enable; }
        bool getEnable() const { return _enabled; }

    private:
        bool _enabled;
        EntityID _id;
};

#endif /* !AENTITY_HPP_ */
