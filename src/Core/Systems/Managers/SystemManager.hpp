/*
** EPITECH PROJECT, 2021
** redCodeEngine
** File description:
** SystemManager
*/

#ifndef SYSTEMMANAGER_HPP_
#define SYSTEMMANAGER_HPP_

#include "System.hpp"
#include "GlobalVariables.hpp"
#include "ComponentManager.hpp"
#include <unordered_map>

class SystemManager {
    public:
        SystemManager();
        ~SystemManager();

        template<class T, class... Args>
        T *addSystem(Args&& ...systemArgs)
        {
            const SystemTypeID systemTypeID = T::_systemTypeID;

            auto it = _systems.find(systemTypeID);
            if (it != _systems.end() && it->second != nullptr)
                return (T *)it->second;
            void *mem = malloc(sizeof(T));
            if (mem == nullptr) {
                LOG_F(ERROR, "Could not allocate space for system : \'%s\' (%d bytes)", typeid(T).name(), sizeof(T));
                //TODO Make your own execptions to be catched by the main engine
                throw std::exception();
            }
            T *system = new T(std::forward<Args>(systemArgs)...);
            _systems[systemTypeID] = system;
            _systemsToExecute.push_back(system);
            return system;
        }

        void Update(float dt);
    protected:
        std::vector<ASystem *> _systemsToExecute;
        std::unordered_map<SystemTypeID, ASystem *> _systems;


    private:
};

#endif /* !SYSTEMMANAGER_HPP_ */
