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

int main(void)
{
    std::cout << "---- STARTING MAIN ----" << std::endl;
    EntityManager manager;

    manager.createEntity<Bomb>();
    std::cout << std::endl;
    manager.createEntity<Bomb>();
    std::cout << std::endl;
    manager.destroyEntity(0);
    manager.cleanDestroyedEntities();
    //Bomb *test = new Bomb();
    //Bomb *nb = new Bomb();

    // std::cout << tab.addObjectToTable(test) << std::endl;
    // std::cout << tab.addObjectToTable(nb) << std::endl;
    // std::cout << nb->getEntityID() << std::endl;
    // std::cout << test->getEntityTypeID() << std::endl;
    std::cout << "---- ENDING MAIN ----" << std::endl;
    return 0;
}