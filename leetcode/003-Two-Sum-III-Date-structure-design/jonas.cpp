#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <time.h>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
protected:
	unordered_map<int, size_t> hash;

public:
	void add(int val) {
		hash[val] = hash.end() == hash.find(val) ? 1 : hash[val] + 1;
	}
	bool find(int val) {
		int complement;

		for(auto const &entry: hash) {
			complement = val - entry.first;

			if (hash.end() != hash.find(complement)) {
				if (complement == entry.first) {
					if (entry.second > 1) {
						return true;
					}
				} else {
					return true;
				}

			}
		}

		return false;
	}
};


int main()
{
	// Testing
	vector<int> int_arr = {-3, 0, 3, 4, 3 };
	vector<int> find_arr = {2, 3, 4, 5, 6, 7, 8, 9, -2};

	Solution s;

	for (size_t i = 0; i < int_arr.size(); i++) {
		s.add(int_arr[i]);
	}

	for (size_t i = 0; i < find_arr.size(); i++) {
		if (s.find(find_arr[i])) {
			cout << "Solution found for " << find_arr[i] <<endl;
		} else {
			cout << "Solution not found for " << find_arr[i] <<endl;
		}
	}

	return 0;
}
