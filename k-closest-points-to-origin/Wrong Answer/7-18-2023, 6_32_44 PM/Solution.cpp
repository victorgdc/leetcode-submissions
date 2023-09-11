// https://leetcode.com/problems/k-closest-points-to-origin

class Solution {
public:
    static bool cmp (pair<int, vector<int>> a, pair<int, vector<int>> b) {
        return a.first < b.first;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, vector<int>>> info;
        vector<vector<int>> ans;

        for (int i = 0; i < points.size(); i++) {
            int d = sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            info.push_back(make_pair(d, points[i]));
        }

        sort(info.begin(), info.end(), cmp);
        
        for (int i = 0; i < k; i++) {
            ans.push_back(info[i].second);
        }

        return ans;
    }
};