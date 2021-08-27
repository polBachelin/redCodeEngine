/*
** EPITECH PROJECT, 2021
** redCodeEngine
** File description:
** SceneManager
*/

#include "SceneManager.hpp"

SceneManager::SceneManager(SystemManager &systemManager, EntityManager &entityManager) :
_entityManager(entityManager), _systemManager(systemManager)
{
}

// SceneManager::~SceneManager()
// {
// }

void SceneManager::update(float dt)
{
    if (_currentScene == nullptr) {
        LOG_F(INFO, "No current scene");
        return;
    }
    _systemManager.update(dt);
    _currentScene->update();
    _entityManager.cleanDestroyedEntities();
}