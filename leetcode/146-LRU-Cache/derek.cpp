#include <cstdio>
#include <list>
#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }

    int get(int key) {
        if (_map.find(key) == _map.end()) {
            return -1;
        } else {
            int value = _map[key]->second;
            touch(key, value);
            return value;
        }
    }

    void put(int key, int value) {
        // found
        if (_map.find(key) != _map.end()) {
            touch(key, value);

        // not found
        } else {
            // cache is full
            if (_capacity == _map.size()) {
                // remove key from hash table
                _map.erase(_list.back().first);

                // remove the last node
                _list.pop_back();
            }
            // add new node to list
            _list.push_front(make_pair(key, value));

            // add new key to hash table
            _map[key] = _list.begin();
        }
    }

    void touch(int key, int value) {
        // remove target node
        auto target = _map[key];
        _list.erase(target);
        // add target node to front of list
        _list.push_front(make_pair(key, value));
        // update hash table
        _map[key] = _list.begin();
    }
private:
    // doubley linked list, node.first = key, node.second = value
    list<pair<int, int>> _list;
    // hash table (key -> list node iterator)
    unordered_map<int, list<pair<int, int>>::iterator> _map;
    // capacity;
    int _capacity;
};

int main()
{
	int capacity = 2;
	LRUCache cache(capacity);

	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << endl;
	cache.put(3, 3);
	cout << cache.get(2) << endl;
	cache.put(4, 4);
	cout << cache.get(1) << endl;
	cout << cache.get(3) << endl;
	cout << cache.get(4) << endl;

	return 0;
}
