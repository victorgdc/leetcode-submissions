// https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> a(8, 0), b(8, 0);
        int n = moves.size();

        for (int i = 0; i < n; i++) {

            int r = moves[i][0], c = moves[i][1];

            vector<int>& player = (i % 2 == 0) ? a : b;

            player[r]++;
            player[c+3]++;
            if (r == c) player[6]++;
            if (r == (2-c)) player[7]++;

        }

        for (int i = 0; i < 8; i++) {
            if (a[i] == 3) return "A";
            else if (b[i] == 3) return "B";
        }

        return moves.size() == 9 ? "Draw" : "Pending";
    }
};