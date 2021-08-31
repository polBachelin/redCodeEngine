/*
** EPITECH PROJECT, 2021
** redCodeEngine
** File description:
** Scene
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include "AScene.hpp"

template<class T>
class Scene : public AScene {
    public:
        Scene() {};
        ~Scene() {};

        virtual void start() override;
        virtual void update() override;
        virtual void end() override;

        SceneTypeID getSceneTypeID() const { return _sceneTypeID; }
        static const SceneTypeID _sceneTypeID;
};

template<class T>
const SceneTypeID Scene<T>::_sceneTypeID = TypeIDCounter<AScene>::get<T>();

#endif /* !SCENE_HPP_ */
