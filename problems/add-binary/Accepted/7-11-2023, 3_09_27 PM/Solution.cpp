// https://leetcode.com/problems/add-binary

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0, i, j;
        int lena = a.size();
        int lenb = b.size();
        string res;
        stack<char> aux;

        for (i = lena-1, j = lenb-1; i >= 0 && j >= 0; i--, j--) {
            if (b[j] == '0') {
                if (a[i] == '1' && carry == 0) {
                    aux.push('1');
                }
                else if (a[i] == '1' && carry == 1) {
                    aux.push('0');
                }
                else if (a[i] == '0' && carry == 0) {
                    aux.push('0');
                }
                else if (a[i] == '0' && carry == 1) {
                    aux.push('1');
                    carry = 0;
                }
            }
            else if (b[j] == '1') {
                if (a[i] == '1' && carry == 0) {
                    aux.push('0');
                    carry = 1;
                }
                else if (a[i] == '1' && carry == 1) {
                    aux.push('1');
                }
                else if (a[i] == '0' && carry == 0) {
                    aux.push('1');
                }
                else if (a[i] == '0' && carry == 1) {
                    aux.push('0');
                }
            }
        }

        while (i >= 0) {
            if (carry == 1 && a[i] == '0') {
                aux.push('1');
                carry = 0;
            }
            else if (carry == 1 && a[i] == '1') {
                aux.push('0');
            }
            else {
                aux.push(a[i]);
            }
            i--;
        }
        
        while (j >= 0) {
            if (carry == 1 && b[j] == '0') {
                aux.push('1');
                carry = 0;
            }
            else if (carry == 1 && b[j] == '1') {
                aux.push('0');
            }
            else {
                aux.push(b[j]);
            }
            j--;
        }
        
        if (carry == 1) aux.push('1');

        while (!aux.empty()) {
            res.push_back(aux.top());
            aux.pop();
        }

        return res;
    }
};