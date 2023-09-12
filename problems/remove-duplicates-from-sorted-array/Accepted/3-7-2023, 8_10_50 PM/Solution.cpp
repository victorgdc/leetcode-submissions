// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ipos = 1;
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i-1]) {
                nums[ipos] = nums[i];
                ipos++;
            }
        }

        return ipos;
    }
};