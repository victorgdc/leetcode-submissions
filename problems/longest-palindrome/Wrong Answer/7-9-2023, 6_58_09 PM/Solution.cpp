// https://leetcode.com/problems/longest-palindrome

class Solution {
public:
    int longestPalindrome(string s) {
        int sum = 0;
        unordered_map<char, int> counter;

        for (auto c : s) {
            counter[c]++;
        }
        for (auto c : counter) {
            if (c.second % 2) sum--;
            sum += c.second;
        }

        return sum+1;
    }
};