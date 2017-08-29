class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
		return getSum(nestedList, 1);
	}

	int getSum(vector<NestedInteger> nestedList, int level) {
		int sum = 0;
		for (auto elem: nestedList) {
			if (elem.isInteger()) {
				sum += elem.getInteger() * level;
			} else {
				sum += getSum(elem, level + 1);
			}
		}
		return sum;
	}
}
