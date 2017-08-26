#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;


#define ALPHABET_SIZE 26

class Node {
public:
    Node() :
        children(vector<Node*>(ALPHABET_SIZE, NULL))
    {
        isLeaf = false;
    }

    bool isLeaf;
    vector<Node*> children;
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node;
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node* p = root;
        for (int i = 0; i < word.length(); i++) {
            int idx = charToIndex(word[i]);
            if (p->children[idx] == NULL) {
                p->children[idx] = new Node;
            }
            p = p->children[idx];
        }
        p->isLeaf = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {

		int n = word.length();

		queue<pair<Node*, int>> que;
		que.push(make_pair(root, 0));

		while (!que.empty()) {
			pair<Node*, int> elem = que.front();
			que.pop();
			Node* node = elem.first;
			int pos = elem.second;

            if (pos == n) {
                if (node->isLeaf) {
                    return true;
                } else {
                    continue;
                }
            }

			if (word[pos] != '.') {
				int idx = charToIndex(word[pos]);
				if (node->children[idx] != NULL) {
					que.push(make_pair(node->children[idx], pos+1));
				}
			} else {
				for (int i = 0; i < ALPHABET_SIZE; i++) {
					if (node->children[i] != NULL) {
						que.push(make_pair(node->children[i], pos+1));
					}
				}
			}
		}

		return false;
    }
private:
    int charToIndex(char ch) {
        return ch - 'a';
    }

    Node* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */


int main()
{
	WordDictionary* obj = new WordDictionary();

	vector<string> words = {"bad", "dad", "mad"};
	for (auto w: words) {
		obj->addWord(w);
	}

	vector<string> patterns = {"pad", "bad", ".ad", "b.."};
	for (auto p: patterns) {
		bool ans = obj->search(p);
		printf("%s,\t%d\n", p.c_str(), ans);
	}

	return 0;
}
