// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        int n = s.size();
        char t;
        bool flag = true;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                stack.push(s[i]); 
            else if (s[i] == ')') {
                t = stack.top();
                stack.pop();
                if (t != '(') {
                    flag = false;
                    break;
                }
            }
            else if (s[i] == '}') {
                t = stack.top();
                stack.pop();
                if (t != '{') {
                    flag = false;
                    break;
                }
            }
            else {
                t = stack.top();
                stack.pop();
                if (t != '[') {
                    flag = false;
                    break;
                }
            }
        }
        bool empty = stack.empty();

        return flag && empty;
    }
};