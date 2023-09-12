// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int k = 0;
        int n = nums.size();

        for (int b = n/2; b >= 1; b /= 2) {
            while (k+b < n && nums[k+b] > nums[0]) k += b;
        }

        int left = binarySearch(nums, target, 0, k);
        int right = binarySearch(nums, target, k+1, n-1);

        return left != -1 ? left : right;
    }

    int binarySearch(vector<int> nums, int target, int l, int r) {
        if (l > r) return -1;

        int m = (l+r)/2;

        if(nums[m] > target) {
            return binarySearch(nums, target, l, m-1);
        } 
        else if (nums[m] < target) {
            return binarySearch(nums, target, m+1, r);
        }
        else return m;
    }
};