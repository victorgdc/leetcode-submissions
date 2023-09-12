// https://leetcode.com/problems/maximum-score-of-a-good-subarray

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
       int left, right, ln, rn; 
       left = right = k;
       int min, ans; 
       min = ans = nums[k];
       int n = nums.size();

       while (left > 0 || right < n-1) {

            while (left > 0 && nums[left-1] >= min) left--;
            while (right < n-1 && nums[right+1] >= min) right++;

            ans = max(ans, (right - left + 1) * min);

            ln = (left > 0) ? nums[left-1] : -1;
            rn = (right < n-1) ? nums[right+1] : -1;

            min = max (ln, rn);
       }

        return ans;
    }
};