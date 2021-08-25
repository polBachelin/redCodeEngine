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
using SystemID = u_int64_t;

class ASystem {
    public:
        ASystem(const float &updateInterval = 0) : _updateInterval(updateInterval) {}
        virtual ~ASystem();

        virtual SystemTypeID getSystemTypeID() const = 0;
        virtual const char *getSystemTypeName() const = 0;
        virtual void update() = 0;

        bool getEnabled() const { return _enabled; }
        void setEnabled(bool enable) { _enabled = enable; }

        float getUpdateInterval() const { return _updateInterval; }
        void setUpdateInterval(const float &interval) { _updateInterval = interval; }

        float getTimeSinceLastUpdate() const { return _timeSinceLastUpdate; }
        void setTimeSinceLastUpdate(const float &time) { _timeSinceLastUpdate = time; }
    protected:
        float _updateInterval;
        float _timeSinceLastUpdate;
        bool _enabled;
    private:
};

#endif /* !ASYSTEM_HPP_ */
