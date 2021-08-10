/*
** Pol Bachelin, 2021
** redCodeEngine
** File description:
** ComponentManager
*/

#ifndef COMPONENTMANAGER_HPP_
#define COMPONENTMANAGER_HPP_

#include "Component.hpp"
#include <vector>
#include <unordered_map>

class ComponentManager {
    public:
        ComponentManager();
        ~ComponentManager();

        template<class T, class... Args>
        T *addComponentToEntity(EntityID id, Args&&... args) {
            
        }
        

    protected:
    private:
};

#endif /* !COMPONENTMANAGER_HPP_ */
