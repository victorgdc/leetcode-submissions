// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, j = prices.size()-1;
        int min = 9999, max = 0;

        while (i < j) {
            if (prices[i] < min) min = prices[i];
            if (prices[j] > max) max = prices[j];
            i++; j--;
        }

        return min < max ? max-min : 0;
    }
};