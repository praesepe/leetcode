class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
	for (size_t i = 0, j = numbers.size() - 1; i < j;) {
            if (numbers[i] + numbers[j] == target) {
                return vector<int> {(int)i, (int)j};
            } else if (numbers[i] + numbers[j] < target) {
                i++;
            } else {
                j--;
            }
        }

        throw std::invalid_argument("No solution found"); 
    }
};
