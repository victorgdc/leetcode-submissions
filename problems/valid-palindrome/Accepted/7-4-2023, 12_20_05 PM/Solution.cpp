// https://leetcode.com/problems/valid-palindrome

class Solution {
public:

    string remove_non_alpha(string t) {
        int i = 0;
        int n = t.size();

        while (i < n) {
            if (!isalnum(t[i]) || t[i] == ' ') {
                t.erase(i, 1);
                n--;
            }
            else {
                i++;
            }
        }

        return t;
    }

    string to_lower(string t) {
        for (auto &c : t) {
            c = tolower(c);
        }

        return t;
    }

    bool isPalindrome(string s) {
        s = remove_non_alpha(s);
        s = to_lower(s);
        
        for (int i = 0, j = s.size()-1; i < j; i++, j--) {
            if (s[i] != s[j]) return false;
         }

        return true;
    }
};