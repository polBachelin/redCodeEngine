/*
** Pol Bachelin, 2021
** redCodeEngine
** File description:
** AScene
*/

#ifndef ASCENE_HPP_
#define ASCENE_HPP_

#include "TypeID.hpp"
#include "EntityManager.hpp"
#include "SystemManager.hpp"

using SceneTypeID = TypeID;

class AScene {
    public:
        AScene(SystemManager &systemManager, EntityManager &entityManager)
        : _systemManager(systemManager), _entityManager(entityManager) {};
        virtual ~AScene() {};

        virtual void start() = 0;
        virtual void update() = 0;
        virtual void end() = 0;
        
    protected:
        SystemManager &_systemManager;
        EntityManager &_entityManager;
};

#endif /* !ASCENE_HPP_ */
