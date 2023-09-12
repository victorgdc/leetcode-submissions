// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        int nofislands = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != '0' && !visited[i][j]) {
                    nofislands++;
                    markIsland(grid, visited, i, j, n, m);
                }
            }
        }

        return nofislands;
    }

    void markIsland (vector<vector<char>> grid, vector<vector<bool>>& visited, int i, int j, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m) return;
        if (grid[i][j] == '0' || visited[i][j] == true) return;

        visited[i][j] = true;
        markIsland(grid, visited, i+1, j, n, m);
        markIsland(grid, visited, i-1, j, n, m);
        markIsland(grid, visited, i, j+1, n, m);
        markIsland(grid, visited, i, j-1, n, m);
    }
};