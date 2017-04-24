#include <stdio.h>

#define OFFSTET 2

class Solution {
public:
	int climbStairs(int n) {
		/*
		   int goal = n + OFFSTET;
		   int* stairs = new int[goal + 1];

		   stairs[0] = 0;
		   stairs[1] = 0;
		   stairs[2] = 1;
		   for (int i = OFFSTET + 1; i <= goal ; i++) {
		   stairs[i] = stairs[i - 1] + stairs[i - 2];
		   }

		   delete [] stairs;
		   return stairs[goal];
		   */
		int tn2 = 1, tn1 = 1;

		for (int i = 2; i <= n; i++) {
			int temp = tn1;
			tn1 += tn2;
			tn2 = temp;
		}

		return tn1;
	}
};
