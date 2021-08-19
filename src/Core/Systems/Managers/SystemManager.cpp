/*
** EPITECH PROJECT, 2021
** redCodeEngine
** File description:
** SystemManager
*/

#include "SystemManager.hpp"

SystemManager::SystemManager()
{
    LOG_F(INFO, "Initializing the System Manager");
}

SystemManager::~SystemManager()
{
    LOG_F(INFO, "Cleaning System Manager");
    for (std::vector<ASystem *>::reverse_iterator it = _systemsToExecute.rbegin(); it != _systemsToExecute.rend(); it++) {
        delete (*it);
        *it = nullptr;
    }
}

void SystemManager::update(float tick_time)
{
    for (ASystem *it : _systemsToExecute) {
        it->setTimeSinceLastUpdate(it->getTimeSinceLastUpdate() + tick_time);
        if (it->getEnabled() && it->getTimeSinceLastUpdate() > it->getUpdateInterval()) {
            it->update();
            it->setTimeSinceLastUpdate(0.0f);
        }
    }
}