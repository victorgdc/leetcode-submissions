// https://leetcode.com/problems/binary-search

using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        return bsearch(nums, target, l, r);
    }

    int bsearch(vector<int>& nums, int target, int l, int r) {
        if (l > r) return -1;

        int m = (l+r)/2;
        if (nums[m] > target) {
            r = m - 1;
            return bsearch(nums, target, l, r);
        } else if (nums[m] < target) {
            l = m + 1;
            return bsearch(nums, target, l, r);
        } else {
            return m;
        }
    }
};