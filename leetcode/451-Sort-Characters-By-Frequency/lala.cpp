#include <string>
#include <unordered_map>
#include <map>

using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;
        multimap<int, char> mm;

        // counting
        for (const auto c : s) {
            count[c]++;
        }

        // build bst
        for (const auto itr : count) {
            mm.insert(make_pair(itr.second, itr.first));
        }

        // compute result
        string result;
        for (auto itr = mm.rbegin() ; itr != mm.rend(); itr++) {
            result += string(itr->first, itr->second);
        }

        return result;
    }
};
