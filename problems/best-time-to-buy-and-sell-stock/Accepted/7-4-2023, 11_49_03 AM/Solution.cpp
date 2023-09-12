// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int least = INT_MAX;
        int profit = 0;
        int n = prices.size();

        for (int i = 0; i < n; i++) {
            if (prices[i] < least) least = prices[i];
            if (prices[i] - least > profit) profit = prices[i] - least;
        }

        return profit;
    }
};