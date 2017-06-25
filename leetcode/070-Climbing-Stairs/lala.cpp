#include <stdio.h>
#include <unordered_map>

using namespace std;

class Solution {
private:
	int solve_recursive(int n) {
		if (n == 0 || n == 1) return 1;

		return solve_recursive(n - 1) + solve_recursive(n - 2);
	}

	int recursive_with_memorization(int n, unordered_map<int, int>& cache) {
		// check cache
		auto answer = cache.find(n);
		if (answer != cache.end()) return answer->second;

		// compute result
		if (n == 0 || n == 1) return 1;
		int result = recursive_with_memorization(n - 1, cache) + recursive_with_memorization(n - 2, cache);

		// set cache
		cache[n] = result;

		return result;
	}

	int solve_recursive_with_memorization(int n) {
		unordered_map<int, int> cache;

		return recursive_with_memorization(n, cache);
	}

	int solve_dp(int n) {
		int* stairs = new int[n + 1];

		stairs[0] = 1;
		stairs[1] = 1;
		for (int i = 2; i <= n; i++) {
			stairs[i] = stairs[i - 1] + stairs[i - 2];
		}

		int result = stairs[n];
		delete [] stairs;

		return result;
	}

	int solve_dp_spaze_optimization(int n) {
		int result = 1, tn1 = 1, tn2 = 1;

		for (int i = 2; i <= n; i++) {
			result = tn1 + tn2;
			tn2 = tn1;
			tn1 = result;
		}

		return result;
	}

	int solve_math(int n) {
		int np = n + 1;
		double phi = (1 + sqrt(5)) * 0.5;
		double fib = (pow(phi, np) - pow(1 - phi, np)) / sqrt(5);

		return round(fib);
	}
public:
	int climbStairs(int n) {
		return this->solve_dp_spaze_optimization(n);
	}
};
