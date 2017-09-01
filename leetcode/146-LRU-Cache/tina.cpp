class Node {
public:
    Node(int k, int v) {
        key = k;
        val = v;
        prev = NULL;
        next = NULL;
    }

    int key;
    int val;
    Node *prev;
    Node *next;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        head = NULL;
        tail = NULL;
        count = 0;
        maxCapacity = capacity;
    }
    
    int get(int key) {
        unordered_map<int, Node *>::const_iterator it = hash.find(key);
        if (it == hash.end()) {
            /* not found */
            return -1;
        }
        
        touch(it->second);
        return (it->second)->val;
    }
    
    void put(int key, int value) {
        unordered_map<int, Node *>::const_iterator it = hash.find(key);
        if (it == hash.end()) {
            /* not found */
            Node *node = new Node(key, value);
            insert(node);
            hash[key] = node;
            evict();
        } else {
            (it->second)->val = value;
            touch(it->second);
        }
    }
    
private:
    void touch(Node *node) {
        remove(node);
        insert(node);
    }
    
    void remove(Node *node) {
        if (node == NULL) return;
        
        if (node->prev != NULL) {
            node->prev->next = node->next;
        } else {
            /* node is head */
            head = node->next;
        }
        
        if (node->next != NULL) {
            node->next->prev = node->prev;
        } else {
            /* node is tail */
            tail = node->prev;
        }
        count--;
    }
    
    void insert(Node *node) {
        if (node == NULL) return;
        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            head->prev = node;
            node->next = head;
            node->prev = NULL;
            head = node;
        }
        count++;
    }
    
    void evict() {
        if (count <= maxCapacity)  return;        
        if (tail == NULL)  return;
        
        Node *prev = tail->prev;
        if (prev != NULL) {
            prev->next = NULL;
        }
        hash.erase(tail->key);
        free(tail);
        tail = prev;
        count--;
    }
    
    unordered_map<int, Node *> hash;
    Node *head;
    Node *tail;
    int count;
    int maxCapacity;
};
