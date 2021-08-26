/*
** EPITECH PROJECT, 2021
** redCodeEngine
** File description:
** SceneManager
*/

#include "SceneManager.hpp"

// SceneManager::SceneManager()
// {
// }

// SceneManager::~SceneManager()
// {
// }

void SceneManager::update()
{
    _currentScene->update();
}