typedef struct Node {
    struct Node *nodes[26];
    bool isWord;
} Node;

Node *nodeCreate() {
    return (Node *) calloc(1, sizeof(Node));
}

typedef struct {
    Node *root;
} WordDictionary;

bool searchNode(Node *, char *);

/** Initialize your data structure here. */
WordDictionary* wordDictionaryCreate() {
    WordDictionary *ret = calloc(1, sizeof(WordDictionary));
    ret->root = nodeCreate();
    
    return ret;
}

/** Adds a word into the data structure. */
void wordDictionaryAddWord(WordDictionary* obj, char* word) {
    Node *node = obj->root;
    
    while (*word) {
        int idx = *word - 'a';
        
        if (!node->nodes[idx]) node->nodes[idx] = nodeCreate();
        
        node = node->nodes[idx];
        word++;
    }
    
    node->isWord = true;
}

/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
bool wordDictionarySearch(WordDictionary* obj, char* word) {
    return searchNode(obj->root, word);
}

bool searchNode(Node *node, char *word) {
    if (!node) return false;
    if (!*word) return node && node->isWord;
    
    if (*word == '.') {
        for (int i=0; i<26; i++) {
            if (node->nodes[i] && searchNode(node->nodes[i], word+1)) return true;
        }
        
        return false;
    }
    
    int idx = *word - 'a';
    
    return node->nodes[idx] && searchNode(node->nodes[idx], word+1);
} 

void wordDictionaryFree(WordDictionary* obj) {
    freeNode(obj->root);
    free(obj);
}

void freeNode(Node *node) {
    if (!node) return;
    
    for (int i=0;i<26;i++) {
        if (node->nodes[i]) freeNode(node->nodes[i]);
    }
    
    free(node);
}

/**
 * Your WordDictionary struct will be instantiated and called as such:
 * struct WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);
 * bool param_2 = wordDictionarySearch(obj, word);
 * wordDictionaryFree(obj);
 */
