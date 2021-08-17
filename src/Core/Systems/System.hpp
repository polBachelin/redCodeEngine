/*
** EPITECH PROJECT, 2021
** redCodeEngine
** File description:
** System
*/

#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_

#include "ASystem.hpp"
#include "loguru.hpp"

template<class T>
class System : public ASystem {
    public:
        System() { LOG_F(INFO, "Creating System %s", typeid(T).name()); };
        virtual ~System();

        static const SystemTypeID _systemTypeID;
        virtual const SystemTypeID getSystemTypeID() const override
        {
            return _systemTypeID;
        }

        virtual const char *getSystemTypeName() const override
        {
            static const char *systemTypeName { typeid(T).name() };
            return systemTypeName;
        }

        virtual void Update() override {}
    protected:
    private:
};


//This forces the compiler to create an instance of Component T in order to set its unique identifier
template<class T>
const SystemTypeID System<T>::_systemTypeID = TypeIDCounter<ASystem>::get<T>();

#endif /* !SYSTEM_HPP_ */
