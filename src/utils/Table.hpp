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

class Table {

    using Entry = std::pair<EntityID, AEntity *>;
    public:
        Table() {
            increaseTable();
        }
        ~Table() {}

        EntityID addObjectToTable(AEntity *object) {
            EntityID i = 0;
            EntityID id = 0;

            for (; i < _table.size(); i++) {
                if (_table[i].second == nullptr) {
                    _table[i].second = object;
                    id = EntityID(i);
                    _table[i].first = id;
                    std::cout << "Adding object to table\n";
                    return id;
                }
            }
            increaseTable();
            _table[i].first = 1;
            _table[i].second = object;
            return EntityID(i);
        }

        void removeObjectFromData(const EntityID &data) const {
            for (auto i : _table) {
                if (i.first != -1)
                    std::cout << "Entity : " << i.first << std::endl;
            }
            AEntity *e = _table[data].second;
            e = nullptr;
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
