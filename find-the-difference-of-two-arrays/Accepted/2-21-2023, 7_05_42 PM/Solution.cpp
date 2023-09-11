// https://leetcode.com/problems/find-the-difference-of-two-arrays

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> map1, map2;
        int tam1 = nums1.size(), tam2 = nums2.size();
        vector<int> dif1, dif2;
        vector<vector<int>> result;

        for (int i = 0; i < tam1; i++) {
            map1[nums1[i]] = false;
        }

        for (int i = 0; i < tam2; i++) {
            map2[nums2[i]] = false;
        }

        for (int i = 0; i < tam1; i++) {
            if (map2.find(nums1[i]) == map2.end() && map1[nums1[i]] == false) {
                dif1.push_back(nums1[i]);
                map1[nums1[i]] = true;
            }
        }

        for (int i = 0; i < tam2; i++) {
            if (map1.find(nums2[i]) == map1.end() && map2[nums2[i]] == false) {
                dif2.push_back(nums2[i]);
                map2[nums2[i]] = true;
            }
        }

        result.push_back(dif1); result.push_back(dif2);

        return result;

    }
};