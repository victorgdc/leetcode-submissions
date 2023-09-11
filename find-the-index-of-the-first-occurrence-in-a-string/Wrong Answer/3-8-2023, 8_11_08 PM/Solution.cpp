// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:
    int strStr(string s, string t) {
        
        int wstart = 0;
        int n = s.size();
        int m = t.size();


        while (wstart <= (n-m)) {
            
            int i = wstart;
            int j = 0;

            while (s[i] == t[j]) {
                i++; j++;
            }
            if (j == t.size()) return wstart;
            wstart++;

        }

        return -1;

    }
};