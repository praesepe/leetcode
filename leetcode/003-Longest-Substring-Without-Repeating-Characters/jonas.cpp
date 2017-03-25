class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int length = 0;
		unordered_map<char, size_t> loc;

		if (s.empty()) {
			return 0;
		}

		for(size_t i = 0, j = 0; i < s.size(); i++) {
			if (loc.end() != loc.find(s.at(i))) {
				j = max(loc[s.at(i)] + 1, j);
			}
			loc[s.at(i)] = i;
			length = max(length, (int)(i + 1 - j));
		}
		return length;

        //throw std::invalid_argument("No solution found"); 
    }
};
