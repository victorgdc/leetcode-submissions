// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int>> sets;
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int j = i+1;
            int k = nums.size()-1;

            if (nums[i] > 0 || nums[k] < 0) break;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k]; 
                if (sum == 0) {
                    sets.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if (sum < 0) {
                    j++;
                }
                else {
                    k--;
                }
            }
        }
        for (auto triplet : sets) {
            ans.push_back(triplet);
        }

        return ans;
    }
};