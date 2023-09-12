// https://leetcode.com/problems/rank-transform-of-an-array

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int tam = arr.size(), rank = 1;
        vector<int> sorted = arr;
        
        if (tam == 0) return arr;

        sort(sorted.begin(), sorted.end());

        vector<int> index(sorted[tam-1]+1);
        
        index[sorted[0]] = rank;
        rank++;
         
        for (int i = 1; i < tam; i++) {
            if (sorted[i] != sorted[i-1]) {
                index[sorted[i]] = rank;
                rank++;
            }
        }

        for (int i = 0; i < tam; i++) {
            arr[i] = index[arr[i]];
        }

        return arr;
    }
};