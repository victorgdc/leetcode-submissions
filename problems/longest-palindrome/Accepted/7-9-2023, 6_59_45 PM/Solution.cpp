// https://leetcode.com/problems/longest-palindrome

class Solution {
public:
    int longestPalindrome(string s) {
        int sum = 0;
        bool has_odd = false;
        unordered_map<char, int> counter;

        for (auto c : s) {
            counter[c]++;
        }
        for (auto c : counter) {
            if (c.second % 2) {
                sum--;
                has_odd = true;
            }
            sum += c.second;
        }

        return has_odd ? sum+1 : sum;
    }
};