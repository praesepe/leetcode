#include <cstdio>
#include <ctime>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
		// found this value
		if (mp.find(val) != mp.end()) {
			return false;
		}

		// add this value to nums and add relation between val and the position of nums array in hashmap
		nums.push_back(val);
		mp[val] = nums.size() - 1;
		return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
		// not found this value
		if (mp.find(val) == mp.end()) {
			return false;
		}

		// swap target and last value to keep constant time for removing element
		int last = nums.back();
		mp[last] = mp[val];
		nums[mp[val]] = last;
		nums.pop_back();
		mp.erase(val);
		return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
		int pos = rand() % nums.size();
        return nums[pos];
    }
private:
	// <int, int> => <val, pos>
	unordered_map<int, int> mp;
	vector<int> nums;
};

int main() {
	RandomizedSet randomSet;

	// Inserts 1 to the set. Returns true as 1 was inserted successfully.
	cout << randomSet.insert(1) << endl;

	// Returns false as 2 does not exist in the set.
	cout << randomSet.remove(2) << endl;

	// Inserts 2 to the set, returns true. Set now contains [1,2].
	cout << randomSet.insert(2) << endl;

	// getRandom should return either 1 or 2 randomly.
	cout << randomSet.getRandom() << endl;

	// Removes 1 from the set, returns true. Set now contains [2].
	cout << randomSet.remove(1) << endl;

	// 2 was already in the set, so return false.
	cout << randomSet.insert(2) << endl;

	// Since 2 is the only number in the set, getRandom always return 2.
	cout << randomSet.getRandom() << endl;


	return 0;
}
