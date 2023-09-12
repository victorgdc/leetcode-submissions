// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:
    int strStr(string s, string t) {
        
        int i, j;

        for (i = 0; i < s.size();) {

            j = 0;
            while(i < s.size() && j < t.size() && t[j] == s[i]) {
                cout << "sao iguais" << endl;
                j++; i++;
            }

            if (j == t.size()) return i-j;
            
            i++;
        }

        return -1;

    }
};