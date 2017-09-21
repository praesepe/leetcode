#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        // build a frequence map
        unordered_map<char, int> freq;
        for (auto c: s) {
            freq[c]++;
        }

        // put them into an array
        vector<pair<char, int>> array;
        for (auto it: freq) {
            array.push_back(make_pair(it.first, it.second));
        }

        // sort array
        sort(array.begin(), array.end(), [](pair<char, int>& a, pair<char, int>& b) {
            return a.second > b.second;
        });

        //
        string result;
        for (auto it: array) {
            result.append(it.second, it.first);
        }
        return result;
    }
};

int main() {
	string s1 = "tree";
	string s2 = "eeee";

	Solution slt;
	string r = slt.frequencySort(s2);
	cout << r << endl;

	return 0;
}
