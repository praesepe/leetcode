class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0) {
            return;
        }

        // prepare
        int m = board.size();
        int n = board[0].size();

        // top and bottom row
        for (int y = 0; y < n; y++) {
            if (board[0][y] == 'O') {
                bfs(board, 0, y);
            }
            if (board[m-1][y] == 'O') {
                bfs(board, m-1, y);
            }
        }

        // right and left column
        for (int x = 0; x < m; x++) {
            if (board[x][0] == 'O') {
                bfs(board, x, 0);
            }
            if (board[x][n-1] == 'O') {
                bfs(board, x, n-1);
            }
        }

        // finally, flip all 'O' to 'X'
        // and then flip all 'V' to 'O'
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (board[x][y] == 'O') {
                    board[x][y] = 'X';
                }
                if (board[x][y] == 'V') {
                    board[x][y] = 'O';
                }
            }
        }
    }
private:
    void bfs(vector<vector<char>>& board, int x, int y) {
        // prepare
        int m = board.size();
        int n = board[0].size();

        board[x][y] = 'V';
        queue<pair<int, int>> que;
        que.push(make_pair(x, y));

        while (!que.empty()) {
            pair<int, int> node = que.front();
            que.pop();

            x = node.first;
            y = node.second;

            // up
            if (x-1 >= 0 && board[x-1][y] == 'O') {
                board[x-1][y] = 'V';
                que.push(make_pair(x-1, y));
            }
            // right
            if (y+1 < n && board[x][y+1] == 'O') {
                board[x][y+1] = 'V';
                que.push(make_pair(x, y+1));
            }
            // down
            if (x+1 < m && board[x+1][y] == 'O') {
                board[x+1][y] = 'V';
                que.push(make_pair(x+1, y));
            }
            // left
            if (y-1 >= 0 && board[x][y-1] == 'O') {
                board[x][y-1] = 'V';
                que.push(make_pair(x, y-1));
            }
        }
    }
};

