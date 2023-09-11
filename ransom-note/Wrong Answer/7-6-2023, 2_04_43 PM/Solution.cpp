// https://leetcode.com/problems/ransom-note

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.size();
        int m = magazine.size();

        // if (n != m) return false;

        unordered_map<char, int> rh, mh;

        for (int i = 0; i < n; i++) {
            rh[ransomNote[i]]++;
        }
        for (int i = 0; i < m; i++) {
            mh[magazine[i]]++;
        }

        for (int i = 0; i < n; i++) {
           if (rh[ransomNote[i]] != mh[ransomNote[i]]) return false; 
        }

        return true;
    }
};