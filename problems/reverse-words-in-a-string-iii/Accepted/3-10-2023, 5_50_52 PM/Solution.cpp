// https://leetcode.com/problems/reverse-words-in-a-string-iii

class Solution {
public:
    string reverseWords(string s) {
        
        int start = 0, end;
        int n = s.size();

        for (int i = 0; i <= n; i++) {
            
            if (i == n || s[i] == ' ') {

                end = i-1;
                
                while(start < end) {
                    swap(s[start], s[end]);
                    start++; end--;
                }

                start = i+1;

            }
        }

        return s;
    }
};