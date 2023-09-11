// https://leetcode.com/problems/longest-string-chain

class Solution {
public:
    bool check(string s, string t) {
        if (s.size() != t.size() + 1) return false;
        int i, j;
        i = j = 0;
        while (i < s.size()) {
            if (j < t.size() && s[i] == t[j]) {
                i++; j++;
            }
            else i++;
        }

        if (i == s.size() && j == t.size()) return true;
        else return false;
    }

    static bool cmp(string s, string t) {
        return s.size() < t.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);

        sort(words.begin(), words.end(), cmp);

        int global_max = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (check(words[i], words[j]) && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
            }
            global_max = max(global_max, dp[i]);
        }

        return global_max;
    }
};