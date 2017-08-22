#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {

    }

    /** Adds a word into the data structure. */
    // O(|word|)
    void addWord(string word) {
        size_t size = word.size();

        auto table_itr = lookup.find(size);
        if (table_itr == lookup.end()) {
            unordered_set<string> s = { word };
            lookup.insert(make_pair(size, s));
        } else {
            table_itr->second.insert(word);
        }
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        size_t size = word.size();

        // check string size map
        // O(1)
        auto table_itr = lookup.find(size);
        if (table_itr == lookup.end()) return false;

        // check exact match
        // O(|word|)
        unordered_set<string> &s = table_itr->second;
        if (s.find(word) != s.end()) return true;

        // check wildcard
        // O(|word|)
        if (word.find('.') == string::npos) return false;

        // worst case, search
        // O(|S| * |word|)
        for (const auto str : s) {
            bool find = true;
            for (size_t i = 0; i < size; i++) {
                if (word[i] == '.') continue;
                if (str[i] != word[i]) {
                    find = false;
                    break;
                }
            }

            if (find) return true;
        }

        return false;
    }

private:
    unordered_map<size_t, unordered_set<string>> lookup;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
