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
}

void SystemManager::update()
{
    for (ASystem *it : _systemsToExecute) {
        if (it->getEnabled()) {
            it->update();
        }
    }
}