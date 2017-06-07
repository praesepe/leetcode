class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
		vector<int> result;

		if (matrix.empty() || matrix[0].empty()) {
			return result;
		}

        vector<vector<int> > steps = {{0,1}, {1,0}, {0,-1}, {-1,0}};
		vector<int> runs = {matrix[0].size(), matrix.size()-1};
		int round = 0;
		int x = 0;
		int y = -1;

		while (runs[round%2] > 0) {

			for (int i = 0; i < runs[round%2]; i++) {
				x += steps[round%4][0];
				y += steps[round%4][1];
				result.push_back(matrix[x][y]);
			}

			runs[round%2]--;
			round++;
		}

		return result;
    }
};
