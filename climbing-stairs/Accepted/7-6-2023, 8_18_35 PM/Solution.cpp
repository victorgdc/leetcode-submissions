// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    int climbStairs(int n) {
    
        unordered_map<int, int> dp;
        return climbStairs(n, dp);
    }

    int climbStairs(int n, unordered_map<int, int>& dp) {
        
        if (n == 1) return 1;
        if (n == 2) return 2;

        if (dp.find(n) == dp.end()) 
            dp[n] = climbStairs(n-1, dp) + climbStairs(n-2, dp); 

        return dp[n];
    }
};