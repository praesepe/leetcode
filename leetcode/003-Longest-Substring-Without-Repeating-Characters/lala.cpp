#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string::size_type result = 0, right = 0, left = 0;
        for (left = 0; left < s.size(); left++) {
            unordered_set<char> us;
            for (right = left; right < s.size(); right++) {
                if (us.find(s[right]) != us.end()) {
                    break;
                } else {
                    us.insert(s[right]);
                }
            }
			result = max(result, right - left);
		}

        return result;
    }
};
