// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = -1, max = 0;
        unordered_map<int, int> counter;

        for (auto num : nums) {
            counter[num]++;
        }

        for (auto el : counter) {
            if (el.second > max) {
                max = el.second;
                major = el.first;
            }
        }

        return major;
    }
};