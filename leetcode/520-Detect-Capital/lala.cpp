#include <string>
using namespace std;

class Solution {
private:
    bool is_capital(char c) {
        return 'A' <= c && c <= 'Z';
    }
public:
    // Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
    bool detectCapitalUse(string word) {
        bool all_capitals = true;
        bool all_littles = true;
        for (size_t i = 1; i < word.size(); i++) {
            if (this->is_capital(word[i])) {
                all_littles = false;
            } else {
                all_capitals = false;
            }
        }

        return all_littles || (all_capitals && this->is_capital(word[0]));
    }
};
