#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
int evalRPN(vector<string>& tokens) {
	stack<int> compute;
	int num1, num2;
	for (string& s : tokens) {
		if (0 == s.compare("+")) {
			num1 = compute.top();
			compute.pop();
			num2 = compute.top();
			compute.pop();
			compute.push(num2 + num1);
		} else if (0 == s.compare("-")) {
			num1 = compute.top();
			compute.pop();
			num2 = compute.top();
			compute.pop();
			compute.push(num2 - num1);
		} else if (0 == s.compare("*")) {
			num1 = compute.top();
			compute.pop();
			num2 = compute.top();
			compute.pop();
			compute.push(num2 * num1);
		} else if (0 == s.compare("/")) {
			num1 = compute.top();
			compute.pop();
			num2 = compute.top();
			compute.pop();
			compute.push(num2 / num1);
		} else {
			compute.push(stoi(s));
		}
	}

	return compute.top();
}
};
