/*
** Pol Bachelin, 2021
** redCodeEngine
** File description:
** Table
*/

#ifndef TABLE_HPP_
#define TABLE_HPP_

#include <vector>
#include "Entity.hpp"
#include "loguru/loguru.hpp"

template<typename T>
union Data {

    using type = T;
    public:
        T _index;
    private:
        T _value;

    Data() {}
    Data(T index) : _index(index) {}
};

class EntityTable {

    using Entry = std::pair<EntityID, AEntity *>;
    public:
        EntityTable() {
            increaseTable();
        }
        ~EntityTable() {}

        EntityID addObjectToTable(AEntity *object) {
            EntityID i = 0;
            EntityID id = 0;

            for (; i < _table.size(); i++) {
                if (_table[i].second == nullptr) {
                    _table[i].second = object;
                    id = EntityID(i);
                    _table[i].first = id;
                    return id;
                }
            }
            increaseTable();
            _table[i].first = 1;
            _table[i].second = object;
            return EntityID(i);
        }

        void removeObjectFromData(const EntityID &data) {
            _table[data].second = nullptr;
        }

        AEntity *operator[](const EntityID &data) const {
            return _table[data].second;
        }
    protected:
    private:
        void increaseTable() {
            size_t old = _table.size();

            size_t nSize = old + 1024;
            _table.resize(nSize);

            for (EntityID i = old; i < nSize; i++) {
                _table[i] = Entry(-1, nullptr);
            }
        }
        std::vector<Entry> _table;
};

#endif /* !TABLE_HPP_ */
