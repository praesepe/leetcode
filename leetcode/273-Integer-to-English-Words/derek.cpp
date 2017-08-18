#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {
		mp = {
			{0,  "Zero"},
			{1,  "One"},
			{2,  "Two"},
			{3,  "Three"},
			{4,  "Four"},
			{5,  "Five"},
			{6,  "Six"},
			{7,  "Seven"},
			{8,  "Eight"},
			{9,  "Nine"},
			{10, "Ten"},
			{11, "Eleven"},
			{12, "Twelve"},
			{13, "Thirteen"},
			{14, "Fourteen"},
			{15, "Fifteen"},
			{16, "Sixteen"},
			{17, "Seventeen"},
			{18, "Eighteen"},
			{19, "Nineteen"},
			{20, "Twenty"},
			{30, "Thirty"},
			{40, "Forty"},
			{50, "Fifty"},
			{60, "Sixty"},
			{70, "Seventy"},
			{80, "Eighty"},
			{90, "Ninety"}
		};
	}

    string numberToWords(int num) {

		if (num == 0) {
			return mp[0];
		}

		string arr[] = {"", "Thousand", "Million", "Billion"};

		vector<string> ans;
		int round = 0;
		while (num != 0) {
			// process the right most thress digits
			int r = num % 1000;
			if (r > 0) {
				ans.push_back(arr[round]);
				ans.push_back(threeDigits(r));
			}

			// next round
			num = num / 1000;
			round++;
		}

		string result;
		int last = ans.size() - 1;
		for (int i = last; i >=0; i--) {
			if (ans[i].length() == 0) {
				continue;
			}

			if (i == last) {
				result = ans[i];
			} else {
				result = result + " " + ans[i];
			}
		}

		return result;
    }

	string threeDigits(int num) {
		string result;

		int q = num / 100;
		if (q > 0) {
			result += mp[q] + " Hundred";
		}

		int r = num % 100;
		if (r > 0) {
			if (q > 0) {
				result += " ";
			}
			result += twoDigits(r);
		}

		return result;
	}

	string twoDigits(int num)
	{
		string result;

		if (num < 20) {
			result += mp[num];
		} else {
			// digit in ones place
			int b = num % 10;
			// digit in tens place
			int a = num - b;

			if (b == 0) {
				result += mp[a];
			} else {
				result += mp[a] + " " + mp[b];
			}
		}

		return result;
	}

private:
	map<int, string> mp;
};

int main()
{
	int n = 1000000;

	Solution slt;
	string r = slt.numberToWords(n);

	cout << n << endl;
	cout << "'" << r << "'" << endl;

	return 0;
}

