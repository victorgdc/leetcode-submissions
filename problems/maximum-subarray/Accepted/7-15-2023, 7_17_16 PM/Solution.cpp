// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum, max_sum;
        max_sum = sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            // best subarray ending at i
            sum = max(nums[i], sum+nums[i]);
            // best subarray until now
            max_sum = max(sum, max_sum);
        }    
        return max_sum;
    }
};