/*
** Pol Bachelin, 2021
** redCodeEngine
** File description:
** SceneManager
*/

#ifndef SCENEMANAGER_HPP_
#define SCENEMANAGER_HPP_

#include "AScene.hpp"
#include <memory>
#include <algorithm>    // std::find

class SceneManager {
    public:
        SceneManager(SystemManager &systemManager, EntityManager &entityManager);
        ~SceneManager() = default;

        template<class T, class... Args>
        AScene *createScene(Args&&... args) 
        {
            SceneTypeID type = TypeIDCounter<AScene>::get<T>();

            if (std::find(_sceneTypes.begin(), _sceneTypes.end(), type) != _sceneTypes.end()) {
                AScene *s = new T(std::forward<Args>(args)...);
                _scenes[type] = s;
                _sceneTypes.push_back(type);
                LOG_F(INFO, "Created scene with ID : %i || and || TYPE : %s", type, typeid(T).name());
                return s;
            }
            //TODO throw exception trying to create same scene twice
            return nullptr;
        }

        template<class T>
        void openScene()
        {
            SceneTypeID type = TypeIDCounter<AScene>::get<T>();

            if (std::find(_sceneTypes.begin(), _sceneTypes.end(), type) != _sceneTypes.end()) {
                if (_currentScene != nullptr) {
                    _currentScene->end();
                }
                _currentScene = _scenes[type];
                _currentScene->start();
            }
        }

        void update(float dt);
    protected:
        std::vector<AScene *> _scenes;
        std::vector<SceneTypeID> _sceneTypes;
        AScene *_currentScene = nullptr;
        EntityManager &_entityManager;
        SystemManager &_systemManager;
    private:
};

#endif /* !SCENEMANAGER_HPP_ */
