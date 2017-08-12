class Solution {
 public:
	std::vector<std::string> letterCombinations(std::string digits) {
		std::vector<std::string> button = {
			"0",
			"1",
			"abc",
			"def",
			"ghi",
			"jkl",
			"mno",
			"pqrs",
			"tuv",
			"wxyz"
		};

		std::queue<std::string> queue({""});
		std::vector<std::string> result;

		while (!queue.empty()) {
			std::string str = queue.front();
			queue.pop();

			int key = digits[str.size()] - '0';

			for (int i = 0; i < button[key].size(); i++) {
				if (str.size() + 1 == digits.size()) {
					result.push_back(str+button[key][i]);
				} else {
					queue.push(str+button[key][i]);
				}
			}
		}
		return result;
    }
};
