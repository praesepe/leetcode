#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;
class Solution {
private:
	static int plus(int n1, int n2)   { return n2 + n1; }
	static int minus(int n1, int n2)  { return n2 - n1; }
	static int times(int n1, int n2)  { return n2 * n1; }
	static int divide(int n1, int n2) { return n2 / n1; }
public:
	Solution() {
		this->handle.insert(make_pair(string("+"), Solution::plus));
		this->handle.insert(make_pair(string("-"), Solution::minus));
		this->handle.insert(make_pair(string("*"), Solution::times));
		this->handle.insert(make_pair(string("/"), Solution::divide));
	}

	int evalRPN(vector<string>& tokens) {
		stack<int> compute;
		int num1, num2;

		for (string& s : tokens) {
			auto action = this->handle.find(s);
			if (action == this->handle.end()) {
				compute.push(stoi(s));
			} else {
				num1 = compute.top();
				compute.pop();
				num2 = compute.top();
				compute.pop();

				compute.push(action->second(num1, num2));
			}
		}

		return compute.top();
	}
private:
	unordered_map<string, function<int (int, int)>> handle;
};
