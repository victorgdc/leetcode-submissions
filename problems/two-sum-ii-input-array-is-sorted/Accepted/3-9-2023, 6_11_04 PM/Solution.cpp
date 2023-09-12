// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        
        int i = 0;
        int j = num.size() - 1;
        vector<int> ans;

        while (i < j) {
            int sum = num[i] + num[j]; 
            
            if (sum == target) {
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
            else if (sum > target) {
                j--;
            }
            else i++;
        }

        return ans;
    }
};