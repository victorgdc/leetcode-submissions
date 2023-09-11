// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int sum = 0;
        int n = nums.size();
        int start = 0;
        int min = INT_MAX;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            while (start <= i && sum >= target) {
                if ((i - start + 1) < min) min = i - start + 1;
                sum -= nums[start];
                start++;
            }
            
        }

        return (min == INT_MAX) ? 0 : min;
    }
};