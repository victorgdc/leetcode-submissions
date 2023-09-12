// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx, i;

        for (i = n-2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) {
                idx = i;
                break;
            }
        }
        if (i < 0) {
            reverse(nums.begin(), nums.end());
        }
        else {
            for (int i = n-1; i > 0; i--) {
                if (nums[i] > nums[idx]) {
                    swap(nums[i], nums[idx]);
                    break;
                }
            } 

            reverse(nums.begin()+idx+1, nums.end());
        }
        
    }
};