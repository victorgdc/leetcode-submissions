// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> index;
        int len = 0; 

        for (int i = 0, j = 0; j < s.size(); j++) {
            if (index.find(s[j]) != index.end() && index[s[j]] >= i) {
                i = index[s[j]] + 1;
            }
            else {
                len = max(len, j-i+1);
            }
            index[s[j]] = j;
        }    
        
        return len;
    }
};