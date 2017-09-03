struct MyNode {
    int key;
    int val;
    MyNode *next;
    MyNode *prev;
    explicit MyNode(int x, int y) : key(x), val(y), next(NULL), prev(NULL) {}
};

class LRUCache {
protected:
    std::unordered_map<int, MyNode*> hash;
    int capacity;
    MyNode* tail;

    void remove(MyNode *node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        this->hash.erase(node->key);
    }

    void add(MyNode *node) {
        MyNode *next = this->head->next;
        this->head->next = node;
        node->prev = this->head;
        node->next = next;
        next->prev = node;
        this->hash[node->key] = node;
    }

public:
    MyNode* head;
    explicit LRUCache(int capacity) {
        this->capacity = capacity;
        this->head = new MyNode(0, 0);
        this->tail = new MyNode(0, 0);
        this->head->next = this->tail;
        this->tail->prev = this->head;
    }

    int get(int key) {
        try {
            MyNode* node = this->hash.at(key);
            remove(node);
            add(node);
            return node->val;
        } catch(const std::out_of_range) {
            return -1;
        }
    }

    void put(int key, int value) {
        MyNode* node;

        if (this->capacity <= 0) {
            return;
        }

        if (this->hash.size() == this->capacity &&
                this->hash.find(key) == this->hash.end()) {
            // remove lru node
            MyNode* lru = this->tail->prev;
            this->remove(lru);
            delete lru;
        }

        if (this->hash.find(key) != this->hash.end()) {
            node = this->hash[key];
            node->val = value;
            remove(node);
            add(node);
        } else {
            node = new MyNode(key, value);
            add(node);
        }
    }
};
