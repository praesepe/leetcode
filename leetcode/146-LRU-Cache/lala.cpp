#include <unordered_map>

using namespace std;

struct CacheNode {
    CacheNode(int key, int value) : next(NULL), prev(NULL), key(key), value(value) {}
    ~CacheNode() {
        if (this->prev) this->prev->next = this->next;
        if (this->next) this->next->prev = this->prev;
    }

    CacheNode* next;
    CacheNode* prev;
    int key;
    int value;
};

class CacheList {
public:
    CacheList() {
        // dummy
        head = new CacheNode(-1, -1);
        tail = head;
    }

    ~CacheList() {
        CacheNode* ptr = this->head;
        while (ptr) {
            CacheNode* tmp = ptr;
            ptr = ptr->next;

            delete tmp;
        }
    }

    void insert_head(CacheNode* node) {
        // check tail
        if (this->tail == this->head) this->tail = node;

        if (this->head->next) this->head->next->prev = node;
        node->next = this->head->next;
        node->prev = this->head;
        this->head->next = node;
    }

    int shift_tail() {
        // check tail
        if (this->tail == this->head) return -1;

        int key = this->tail->key;

        // shift
        this->tail = this->tail->prev;
        this->tail->next = NULL;

        return key;
    }

    void rewind(CacheNode* node) {
        // check tail
        if (this->tail == this->head) return;

        // if node is head, do nothing
        if (this->head->next == node) return;

        // update tail
        if (this->tail == node) this->tail = this->tail->prev;

        // reconstruct node
        if (node->prev) node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;

        // reconstruct head
        if (this->head->next) this->head->next->prev = node;
        node->next = this->head->next;
        node->prev = this->head;
        this->head->next = node;
    }
private:
    CacheNode* head;
    CacheNode* tail;
};

class LRUCache {
public:
    LRUCache(int capacity) : limit(capacity), size(0) {}

    int get(int key) {
        const auto itr = this->cache.find(key);
        if (itr == this->cache.end()) return -1;

        this->cl.rewind(itr->second);
        return itr->second->value;
    }

    void put(int key, int value) {
        // should insert new node?
        const auto itr = this->cache.find(key);
        if (itr != this->cache.end()) {
            itr->second->value = value;
            this->cl.rewind(itr->second);
            return;
        }

        // check limit
        if (this->limit == this->size) {
            int tail_key = this->cl.shift_tail();
            // since erase will invoke the destructor
            this->cache.erase(tail_key);
        } else {
            this->size++;
        }

        // create new node
        CacheNode* new_entry = new CacheNode(key, value);
        this->cl.insert_head(new_entry);
        this->cache[key] = new_entry;
    }
private:
    int size;
    int limit;
    CacheList cl;
    unordered_map<int, CacheNode*> cache;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
