/*
** Pol Bachelin, 2021
** redCodeEngine
** File description:
** main
*/

#include "Bomb.hpp"
#include "EntityManager.hpp"
#include "EntityPool.hpp"
#include "Transform.hpp"
#include <iostream>
#include "loguru/loguru.hpp"
#include "Engine.hpp"

int main(void)
{
    loguru::g_stderr_verbosity = 1;
    loguru::add_file("latest_readable.log", loguru::Truncate, loguru::Verbosity_INFO);
    LOG_F(INFO, "STARTING MAIN");
    ECS::Engine engine;

    engine.update(1.0f);
    LOG_F(INFO, "ENDING MAIN");
    loguru::shutdown();
    return 0;
}