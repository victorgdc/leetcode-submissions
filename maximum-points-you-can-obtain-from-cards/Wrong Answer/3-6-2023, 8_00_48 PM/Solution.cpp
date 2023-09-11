// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards

class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int minsum = 1000000;
        int sum = 0, totalsum = 0;
        int n = card.size();

        for (int i = 0; i < n; i++) {
            
            totalsum += card[i];
            sum += card[i];

            if (i >= (n-k-1)) {
                minsum = min(minsum, sum);
                sum -= card[i-n+k+1];
            }

        }

        if (k == n) minsum = 0;
        return totalsum - minsum;
    }
};