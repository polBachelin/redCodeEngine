/*
** Pol Bachelin, 2021
** redCodeEngine
** File description:
** Table
*/

#ifndef TABLE_HPP_
#define TABLE_HPP_

#include <vector>


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


template<class T, class dataType, size_t size = 1024>
class Table {

    using Entry = std::pair<dataType, T *>;
    public:
        Table() {
            increaseTable();
        }
        ~Table() {}

        int addObjectToTable(T *object) {
            dataType i = 0;
            for (; i < _table.size(); i++) {
                if (_table[i].second == nullptr) {
                    _table[i].second = object;
                    _table[i].first = _table[i].first + 1;
                    return i;
                }
            }
            increaseTable();
            _table[i].first = 1;
            _table[i].second = object;
            return i;
        }

        void removeObjectFromData(const dataType &data) const {
            _table[data].second = nullptr;
        }

    protected:
    private:
        void increaseTable() {
            size_t old = _table.size();

            size_t nSize = old + size;
            _table.resize(nSize);

            for (dataType i = old; i < nSize; i++) {
                _table[i] = Entry(0, nullptr);
            }
        }
        std::vector<Entry> _table;
};

#endif /* !TABLE_HPP_ */
