#include <map>
#include <cstdio>
#include <iostream>

using namespace std;

class TwoSum {
public:
	void add(int num) {
		int count = _mp.find(num) != _mp.end() ? _mp[num] : 0;
		_mp[num] = count++;
	}

	bool find(int target) {
		map<int, int>::iterator it = _mp.begin();
		for (; it != _mp.end(); it++) {
			int x = it->first;
			int y = target - x;
			if (x == y) {
				// For duplicates, ensure there are at least two individual numbers.
				if (it->second >= 2) {
					return true;
				}
			} else {
				if (_mp.find(y) != _mp.end()) {
					return true;
				}
			}
		}
		return false;
	}

private:
	map<int, int> _mp;
};

int main () {
	TwoSum ts;

	for (int i = 0; i < 10; i++) {
		ts.add(i);
	}

	for (int i = 0; i < 20; i++) {
		ts.find(i);
	}
}
