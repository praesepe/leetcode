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

        // put character into frequence bucket
        vector<string> bucket(s.length() + 1);
        for (auto it: freq) {
            int n = it.second;
            int c = it.first;
            bucket[n].append(n, c);
        }

        // from descending sorting order
        string result;
        for (int i = bucket.size() - 1; i >= 0; i--) {
            result += bucket[i];
        }
        return result;
    }
};

int main() {
	string s = "tree";

	Solution slt;
	string r = slt.frequencySort(s);
	cout << r << endl;

	return 0;
}
