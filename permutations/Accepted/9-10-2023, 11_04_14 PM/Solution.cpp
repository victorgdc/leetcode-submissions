// https://leetcode.com/problems/permutations

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> partial;
        unordered_set<int> set;

        findPermutation(ans, set, partial, nums, n);

        return ans;
    }

    void findPermutation(vector<vector<int>>& ans, unordered_set<int>& set, vector<int> partial, vector<int> nums, int n) {

        if (n == 0) {
            ans.push_back(partial);
            return;
        }

        int i = 0;
        while (i < nums.size()) {
            if (set.find(nums[i]) == set.end()) {
                partial.push_back(nums[i]);
                set.insert(nums[i]);
                findPermutation(ans, set, partial, nums, n-1);
                partial.pop_back();
                set.erase(nums[i]);   
            }
            i++;
        }

    }
};