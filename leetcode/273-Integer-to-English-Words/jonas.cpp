class Solution {
 protected:
	 std::string implode(std::vector<std::string> &arr) {
		 std::string ans;
		 for (auto s: arr) {
			 ans += s.empty() ? "" : s + " ";
		 }
		 ans.pop_back();
		 return ans;
	 }

 public:
	std::string numberToWords(int num) {
		std::vector<std::string> digits = {
			"",
			"One",
			"Two",
			"Three",
			"Four",
			"Five",
			"Six",
			"Seven",
			"Eight",
			"Nine",
			"Ten",
			"Eleven",
			"Twelve",
			"Thirteen",
			"Fourteen",
			"Fifteen",
			"Sixteen",
			"Seventeen",
			"Eighteen",
			"Nineteen"
		};
		std::vector<std::string> tens = {
			"",
			"",
			"Twenty",
			"Thirty",
			"Forty",
			"Fifty",
			"Sixty",
			"Seventy",
			"Eighty",
			"Ninety"
		};
		std::vector<std::string> larges = {
			"",
			"Thousand",
			"Million",
			"Billion"
		};

		if (num == 0) {
			return "Zero";
		}

		std::vector<std::string> ans;
		for (size_t i = 0; i < 4 && num > 0; i++, num /= 1000) {
			int mod = num % 1000;

			if (mod == 0) {
				continue;
			}

			ans.push_back(larges[i]);
			if (mod % 100 < 20) {
				ans.push_back(digits[mod % 100]);
				mod /=100;
			} else {
				ans.push_back(digits[mod%10]);
				mod /= 10;
				ans.push_back(tens[mod%10]);
				mod /=10;
			}

			if (mod > 0) {
				ans.push_back(digits[mod] + " Hundred");
			}
		}

		std::reverse(ans.begin(), ans.end());
		return this->implode(ans);
	}
};
