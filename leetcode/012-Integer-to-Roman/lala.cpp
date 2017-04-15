#include <vector>
#include <string>

using namespace std;

struct Roman {
    const char* text;
    int num;
};

class Solution {
public:
	string intToRoman(int num) {
		vector<Roman> romans = {
			{ "I", 1 },
			{ "IV", 4 },
			{ "V", 5 },
			{ "IX", 9 },
			{ "X", 10 },
			{ "XL", 40 },
			{ "L", 50 },
			{ "XC", 90 },
			{ "C", 100 },
			{ "CD", 400 },
			{ "D", 500 },
			{ "CM", 900 },
			{ "M", 1000 },
		};

		string result;
		int tail = romans.size() - 1;
		while (num != 0) {
			int times = num / romans[tail].num;
			for (int i = 0; i < times; i++) {
				num -= romans[tail].num;
				result.append(romans[tail].text);
			}
			tail--;
		}

		return result;
	}
};
