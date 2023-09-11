// https://leetcode.com/problems/contains-duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> counter;

        for (auto num : nums) {
            counter[num]++;
            if (counter[num] == 2) return true;
        }
        return false;
    }
};