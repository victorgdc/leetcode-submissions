// https://leetcode.com/problems/rank-transform-of-an-array

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int tam = arr.size(), rank = 1;
        vector<int> sorted = arr;
        
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> map;

        for (int i = 0; i < tam; i++) {
            if (map.find(sorted[i]) == map.end()) {
                map[sorted[i]] = rank;
                rank++; 
            }
        }

        for (int i = 0; i < tam; i++) {
            arr[i] = map[arr[i]];
        }

        return arr;
    }
};