// https://leetcode.com/problems/contains-duplicate-ii

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int start, end;
        int n = nums.size();

        for(int i = 0; i < n-1; i++) {
            start = i;
            for (int j = i+1; j < n;) {
                if (nums[start] == nums[j]) {
                    if (j-start <= k) return true;
                    else {
                        start = j;
                        j++;
                    }
                }
                else j++;
            }
        }
        return false;
    }
};