// https://leetcode.com/problems/01-matrix

class Solution {
public:
    vector<int> DIR = {0, 1, 0, -1, 0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) q.emplace(i, j);
                else mat[i][j] = -1;
            }
        }

        while(!q.empty()) {
            auto [row, col] = q.front(); q.pop();

            for (int i = 0; i < 4; i++) {
                int node_row = row + DIR[i];
                int node_col = col + DIR[i+1];
                if (node_row < 0 || node_row == m ||
                node_col < 0 || node_col == n || mat[node_row][node_col] != -1)
                    continue;
                mat[node_row][node_col] = mat[row][col] + 1;
                q.emplace(node_row, node_col);
            }
        }

        return mat;
    }


};