// https://leetcode.com/problems/coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int n = coins.size();
        int ncoins = 0;

        for (int i = n-1; i >=0; i--) {

            while(coins[i] <= amount) {
                amount -= coins[i];
                ncoins++;
            }
            if (amount == 0) return ncoins;
        }

        return -1;
    }
};