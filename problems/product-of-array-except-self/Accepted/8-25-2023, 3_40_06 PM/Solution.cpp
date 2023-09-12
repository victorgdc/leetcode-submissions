// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size(), 1);
        int total = 1;

        for (int i = 1; i < nums.size(); i++) {
            total *= nums[i-1];
            answer[i] = total;
        }
        total = 1;

        for (int i = nums.size()-2; i >=0; i--) {
            total *= nums[i+1];
            answer[i] *= total;
        }

        return answer;
    }
};