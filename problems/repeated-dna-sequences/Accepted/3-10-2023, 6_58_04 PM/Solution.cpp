// https://leetcode.com/problems/repeated-dna-sequences

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        unordered_map<string, int> map;
        vector<string> ans;   
        string t;

        for (int i = 0; i < s.size(); i++) {
            t += s[i];

            if (i >= 9) {
                if (map.find(t) == map.end()) map[t] = 1;
                else map[t]++;
                cout << t << endl;
                t = t.substr(1, t.size() - 1);
            }

        }

        for (auto x: map) {
            if (x.second > 1) ans.push_back(x.first);
        }

        return ans;
    }
};