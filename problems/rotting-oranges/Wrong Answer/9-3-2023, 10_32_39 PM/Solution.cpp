// https://leetcode.com/problems/rotting-oranges

class Solution {
public:
    
    int DIR[5] = {0, -1, 0, 1, 0};
    int orangesRotting(vector<vector<int>>& grid) {
        int nfresh = 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int ans = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int orange = grid[i][j];
                if (orange == 2) {
                    q.push({i, j});
                }
                else if (orange == 1) nfresh++;
            }
        }

        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                auto [x, y] = q.front(); q.pop();
                for (int i = 0; i < 4; i++) {
                    int cx = x + DIR[i];
                    int cy = y + DIR[i+1];

                    if (cx >= 0 && cx < n && cy >= 0 && cy < m && grid[cx][cy] == 1) {
                        nfresh--;
                        grid[cx][cy] = 2;
                        q.push({cx, cy});
                    }
                }
            }
            ans++;
        }

        return nfresh > 0 ? -1 : ans;
    }
};