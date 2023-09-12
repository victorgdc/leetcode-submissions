// https://leetcode.com/problems/swap-adjacent-in-lr-string

using namespace std;
class Solution {
public:
    bool canTransform(string start, string end) {
        string s = start, t = end;

        s.erase(remove(s.begin(), s.end(), 'X'), s.end());
        t.erase(remove(t.begin(), t.end(), 'X'), t.end());

        vector<int> Lst, Len;
        vector<int> Rst, Ren;

        if (s != t)
            return false;

        int n = start.size();

        for (int i = 0; i < n; i++) {
            if (start[i] == 'L') Lst.push_back(i);
            else if (start[i] == 'R') Rst.push_back(i);
        }

        for (int i = 0; i < n; i++) {
            if (end[i] == 'L') Len.push_back(i);
            else if (end[i] == 'R') Ren.push_back(i);
        }

        for (int i = 0; i < Lst.size(); i++) {
            if (Lst[i] < Len[i]) return false;
        }

        for (int i = 0; i < Rst.size(); i++) {
            if (Rst[i] > Ren[i]) return false;
        }

        return true;
    }
};