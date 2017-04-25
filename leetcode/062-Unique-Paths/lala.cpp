#include <stdio.h>

class Solution {
public:
	int uniquePaths(int m, int n) {
		int robot[100 + 1][100 + 1];

		for (int i = 1; i <= m; i++) {
			robot[i][1] = 1;
		}

		for (int i = 1; i <= n; i++) {
			robot[1][i] = 1;
		}

		for (int i = 2; i <= m; i++) {
			for (int j = 2; j<= n; j++) {
				robot[i][j] = robot[i - 1][j] + robot[i][j - 1];
			}
		}

		return robot[m][n];
	}
};
