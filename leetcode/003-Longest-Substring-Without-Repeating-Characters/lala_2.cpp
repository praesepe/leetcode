#include <string>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		string::size_type result = 0, right = 0, left = 0;

		unordered_map<char, string::size_type> um;
		for (right = 0; right < s.size(); right++) {
			char c = s[right];

			unordered_map<char, string::size_type>::iterator itr = um.find(c);
			if (itr != um.end() && itr->second >= left) {
				left = itr->second + 1;
			}

			um[c] = right;
			result = max(result, right - left + 1);
		}

        return result;
    }
};
