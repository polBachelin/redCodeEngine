/*
** Pol Bachelin, 2021
** redCodeEngine
** File description:
** EntityPool
*/

#ifndef ENTITYPOOL_HPP_
#define ENTITYPOOL_HPP_

#include "IEntityPool.hpp"
#include <list>
#include "loguru/loguru.hpp"
#include <typeinfo>

template<class T>
class EntityPool : public IEntityPool {
    public:
        EntityPool() {
            LOG_F(INFO, "Creating entity Pool");
        };
        virtual ~EntityPool() {
            LOG_F(INFO, "Destroying Entity Pool of type : %s", getEntityTypeName());
            for (auto i : _objects) {
                delete i;
            }
        };

        const char *getEntityTypeName() const override {
            static const char *name { typeid(T).name() };
            return name;
        }

        AEntity *createObject() {
            AEntity *e = new T();

            _objects.push_back(e);
            return e;
        }
        void destroyEntity(AEntity *e) {
            _objects.remove(e);
            delete e;
        }
    protected:
        std::list<AEntity *> _objects;
    private:
};

#endif /* !ENTITYPOOL_HPP_ */
