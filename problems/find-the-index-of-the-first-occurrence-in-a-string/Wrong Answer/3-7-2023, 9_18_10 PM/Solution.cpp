// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:
    int strStr(string s, string t) {
        
        int i, j;

        for (i = 0; i < s.size();) {

            j = 0;
            while(t[j] == s[i]) {
                j++; i++;
            }

            if (j == t.size()) return i-j;
            
            i++;
        }

        return -1;

    }
};