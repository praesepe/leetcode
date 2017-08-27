#include <string>
#include <unordered_set>

using namespace std;

#define BRANCH_FACTOR 26
#define GET_INDEX(c) ((c) - 'a')
#define DOT_INDEX GET_INDEX('.')

struct TrieNode {
private:
    void clean(TrieNode* ptr) {
        if (!ptr) return;

        for (auto itr = ptr->jump.begin(); itr != ptr->jump.end(); itr++) {
            this->clean(ptr->children[*itr]);
        }

        if (ptr != this) delete ptr;
    }

public:
    TrieNode() {
        memset(this->children, 0, sizeof(this->children));
        this->is_leaf = false;
    }

    ~TrieNode() {
        this->clean(this);
    }

    unordered_set<size_t> jump;
    TrieNode* children[BRANCH_FACTOR];
    bool is_leaf;
};

class WordDictionary {
private:
    bool dfs(const string &target, size_t pos, TrieNode* root) {
        if (!root) return false;
        if (target.size() == pos) return root->is_leaf;

        // normal case
        if (target[pos] != '.') {
            int index = GET_INDEX(target[pos]);
            return this->dfs(target, pos + 1, root->children[index]);
        } 

        // wildcard
        for (auto itr = root->jump.begin() ; itr != root->jump.end(); itr++) {
            if (this->dfs(target, pos + 1, root->children[*itr])) {
                return true;
            }
        }

        return false;
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        this->root = new TrieNode();
    }

    /** Adds a word into the data structure. */
    // O(|word|)
    void addWord(string word) {
        TrieNode* ptr = this->root;
        for (const auto c : word) {
            int index = GET_INDEX(c);
            if (ptr->children[index] == nullptr) {
                ptr->jump.insert(index);
                ptr->children[index] = new TrieNode();
            }
            ptr = ptr->children[index];
        }
        ptr->is_leaf = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return this->dfs(word, 0, root);
    }
private:
    TrieNode* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
