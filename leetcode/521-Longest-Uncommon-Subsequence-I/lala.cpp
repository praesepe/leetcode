#include <string>

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a.size() > b.size()) {
            return a.size();
        } else if (a.size() < b.size()) {
            return b.size();
        } else {
            return a == b ? -1 : a.size();
        }
    }
};
