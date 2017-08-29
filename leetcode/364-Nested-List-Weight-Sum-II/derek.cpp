class Solution {
public:
	int depthSumInverse(vector<NestedInteger>& nestedList) {
		vector<int> sums;
		helper(nestedList, 0, sums);

		int result = 0;
		for (int i = sums.size(); i >= 0; i--) {
			result += sums[i] * (i + 1);
		}
		return result;
	}

	void helper(vector<NestedInteger> nestedList, int depth, vector<int>& sums) {
		if (depth >= v.size()) {
			v.resize(depth + 1);
		}

		for (auto elem: nestedList) {
			if (elem.isInteger()) {
				sums[depth] += elem.getInteger();
			} else {
				helper(elem.getList(), depth + 1, sums);
			}
		}
	}
}
