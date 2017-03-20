#include <set>
#include <iterator>
#include <iostream>

using namespace std;

class TwoSum {
public:
	void add(int num) {
		this->_nums.insert(num);
	}

	bool find(int target) {
		bool result = false;
		multiset<int>::iterator head = this->_nums.begin();
		multiset<int>::iterator tail = next(this->_nums.begin(), this->_nums.size() - 1);

		while (distance(head, tail) > 0) {
			int sum = *head + *tail;
			if (sum > target) {
				tail--;
			} else if (sum < target) {
				head++;
			} else if (sum == target) {
				result = true;
				break;
			}
		}

		if (result) {
			cout << target << " = " << *head << " + " << *tail << endl;
		} else {
			cout << "cannot find " << target << endl;
		}

		return result;
	}

private:
	multiset<int> _nums;
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
