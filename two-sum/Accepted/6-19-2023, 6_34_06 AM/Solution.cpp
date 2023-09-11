// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> hash;
        vector<int> v;

        for (int i = 0; i < n; i++) {
            int comp = target - nums[i];
            if (hash.find(comp) != hash.end()) {
                v.push_back(i);
                v.push_back(hash[comp]);
                break;
            }
            hash[nums[i]] = i;
        }
        
        return v;
    }
};