// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_hash;
        unordered_map<char, int> t_hash;

        if (s.size() != t.size()) return false;

        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s_hash.count(s[i]) == 0) s_hash[s[i]] = 1;
            else s_hash[s[i]]++;
            
            if (t_hash.count(t[i]) == 0) t_hash[t[i]] = 1;
            else t_hash[t[i]]++;
        }

        for (int i = 0; i < n; i++) {
            if (s_hash[s[i]] != t_hash[s[i]]) return false;
        }

        return true;
    }
};