/*
** EPITECH PROJECT, 2021
** redCodeEngine
** File description:
** Engine
*/

#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include "SystemManager.hpp"
#include "ComponentManager.hpp"
#include "EntityManager.hpp"
#include "SceneManager.hpp"
#include "Clock.hpp"
#include <memory>

namespace ECS {
    class Engine {
        public:
            Engine();
            ~Engine();

            std::shared_ptr<EntityManager> getEntityManager() const;
            std::shared_ptr<ComponentManager> getComponentManager() const;
            std::shared_ptr<SystemManager> getSystemManager() const;
            std::shared_ptr<SceneManager> getSceneManager() const;
            void update(float dt);
        protected:
            Clock _clock;
            std::shared_ptr<SceneManager> _sceneManager;
            std::shared_ptr<EntityManager> _entityManager;
            std::shared_ptr<ComponentManager> _componentManager;
            std::shared_ptr<SystemManager> _systemManager;
        private:
    };
}

#endif /* !ENGINE_HPP_ */
