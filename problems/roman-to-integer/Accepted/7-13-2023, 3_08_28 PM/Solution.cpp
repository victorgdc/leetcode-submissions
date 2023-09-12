// https://leetcode.com/problems/roman-to-integer

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = {{'I', 1}, {'V',5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int total = 0;
        char last = s[0];
        
        for (int i = 0; i < s.size(); i++) {
            if (roman[s[i]] > roman[last]) {
                total += roman[s[i]] - 2*roman[last];
            }
            else {
                total += roman[s[i]];
            }
            last = s[i];
        }
        
        return total;
    }
};