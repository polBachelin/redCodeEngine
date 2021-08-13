/*
** Pol Bachelin, 2021
** redCodeEngine
** File description:
** main
*/

#include "Bomb.hpp"
#include "EntityManager.hpp"
#include "EntityPool.hpp"
#include <iostream>
#include "loguru/loguru.hpp"

int main(void)
{
    loguru::g_stderr_verbosity = 1;
    loguru::add_file("latest_readable.log", loguru::Truncate, loguru::Verbosity_INFO);
    LOG_F(INFO, "STARTING MAIN");
    EntityManager manager;

    manager.createEntity<Bomb>();
    manager.createEntity<Bomb>();    
    manager.destroyEntity(0);
    manager.cleanDestroyedEntities();
    //Bomb *test = new Bomb();
    //Bomb *nb = new Bomb();

    // std::cout << tab.addObjectToTable(test) << std::endl;
    // std::cout << tab.addObjectToTable(nb) << std::endl;
    // std::cout << nb->getEntityID() << std::endl;
    // std::cout << test->getEntityTypeID() << std::endl;
    LOG_F(INFO, "ENDING MAIN");
    loguru::shutdown();
    return 0;
}