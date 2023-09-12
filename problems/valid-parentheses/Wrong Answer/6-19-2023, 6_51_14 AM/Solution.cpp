// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        stack <char> par;
        stack <char> cha;
        stack <char> col;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') par.push('(');
            else if (s[i] == '{') cha.push('{');
            else if (s[i] == '[') col.push(']');
            else if (s[i] == ')') par.pop();
            else if (s[i] == '}') cha.pop();
            else if (s[i] == ']') col.pop();
        }

        return (cha.empty() && par.empty() && col.empty());
    }
};