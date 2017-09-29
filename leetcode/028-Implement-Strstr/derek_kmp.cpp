#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        if (n < m) {
            return -1;
        }
        if (m == 0) {
            return 0;
        }

        vector<int> next(m, 0);
        getNextTable(needle, next);

        int i = 0, j = 0;
        int result = -1;
        while (i < n && j < m) {
            if (j == -1 || haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }
        if (j == m) {
            return i - j;
        }

        return result;
    }
private:
    void getNextTable(string needle, vector<int>& next) {
        next[0] = -1;
        int k = -1;
        int j = 0;
        while (j < needle.length() - 1) {
            if (k == -1 || needle[j] == needle[k]) {
                j++;
                k++;
                next[j] = k;
            } else {
                k = next[k];
            }
        }
    }
};

int main() {
    string haystack = "12abab3";
    string needle = "abab";

    Solution slt;
    int pos = slt.strStr(haystack, needle);
    cout << pos << endl;

    return 0;
}
