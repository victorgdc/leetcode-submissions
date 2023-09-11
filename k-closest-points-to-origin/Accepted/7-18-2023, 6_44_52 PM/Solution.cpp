// https://leetcode.com/problems/k-closest-points-to-origin

class Solution {
public:
    static bool cmp (vector<int> a, vector<int> b) {
        return (a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        sort(points.begin(), points.end(), cmp);

        for (int i = 0; i < k; i++) {
            ans.push_back(points[i]);
        }

        return ans;
    }
};