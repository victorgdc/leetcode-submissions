// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards

class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        
        int n = card.size();
        int sum = accumulate(card.begin(), card.begin() + n - k, 0);
        int total = accumulate(card.begin(), card.end(), 0);
        int ans = total - sum;
        

        for (int i = 0; i < k; i++) {
            
            sum -= card[i];
            sum += card[i + (n-k)];
            ans = max(ans, total - sum);

        }

        return ans;
    }
};