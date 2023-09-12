// https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        int answer = 0;
        unordered_map<int, int> hash;

        for (int i = 0; i < arr.size(); i++) {
            if (hash.find(arr[i] - difference) != hash.end()) {
                hash[arr[i]] = hash[arr[i] - difference] + 1;
            }
            else {
                hash[arr[i]] = 1;
            }
            answer = max(answer, hash[arr[i]]);
        }


        return answer;
    }
};