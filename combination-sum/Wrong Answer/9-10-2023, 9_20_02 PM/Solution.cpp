// https://leetcode.com/problems/combination-sum

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> partial;
        int i = 0;

        backTracking(candidates, ans, partial, i, target);

        return ans;
    }

    void backTracking (vector<int> candidates, vector<vector<int>>& ans, vector<int>& partial, int i, int target) {

        if (target == 0) {
            ans.push_back(partial);
            return;
        }

        while (i < candidates.size() && target >= candidates[i]) {
            partial.push_back(candidates[i]);
            backTracking(candidates, ans, partial, i, target-candidates[i]);
            partial.pop_back();
            i++;
        }

    }
};