public class Solution {

    public int numIslands(char[][] grid) {
        if (grid.length == 0) {
            return 0;
        }
        int i = grid.length - 1;
        int j = grid[0].length - 1;
        Queue<int[]> lands = new LinkedList();
        int ans = 0;
        while (i >= 0) {
            // explore island
            if (grid[i][j] == '1') {
                lands.add(new int[]{i, j});
                grid[i][j] = '0';
                while (!lands.isEmpty()) {
                    int[] pointer = lands.poll();
                    int x = pointer[0];
                    int y = pointer[1];
                    exploreLand(grid, lands, x + 1, y);
                    exploreLand(grid, lands, x - 1, y);
                    exploreLand(grid, lands, x, y + 1);
                    exploreLand(grid, lands, x, y - 1);
                }
                ans++;
            }
            // move worker
            if (grid[i][j] == '0') {
                if (j != 0) {
                    j--;
                } else {
                    i--;
                    j = grid[0].length - 1;
                }
            }
        }

        return ans;
    }

    public void exploreLand(char[][] grid, Queue<int[]> lands, int x, int y) {
        if(x >= 0 && y >= 0 && x < grid.length && y < grid[0].length && grid[x][y] == '1') {
            grid[x][y] = '0';
            lands.add(new int[]{x, y});
        }
    }
    
}