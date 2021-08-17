/*
** EPITECH PROJECT, 2021
** redCodeEngine
** File description:
** ASystem
*/

#ifndef ASYSTEM_HPP_
#define ASYSTEM_HPP_

#include "TypeID.hpp"

using SystemTypeID = TypeID;

class ASystem {
    public:
        ASystem(const float &updateInterval = 0) : _updateInterval(updateInterval) {}
        virtual ~ASystem();

        virtual const SystemTypeID getSystemTypeID() const = 0;
        virtual const char *getSystemTypeName() const = 0;
        virtual void Update() = 0;

        const float getUpdateInterval() const { return _updateInterval; }
        void setUpdateInterval(const float &interval) { _updateInterval = interval; }
    protected:
        float _updateInterval;
    private:
};

#endif /* !ASYSTEM_HPP_ */
