// https://leetcode.com/problems/find-original-array-from-doubled-array

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> original;
        unordered_set<int> set;
        unordered_map<int, bool> hash;
        bool valid = true;

        for (int i = 0; i < changed.size(); i++) {
            set.insert(changed[i]);
        }

        for (int i = 0; i < changed.size(); i++) {
            if (changed[i]%2 == 1) {
                if (set.find(changed[i]*2) == set.end()) {valid = false; break;}
                hash[changed[i]] = false;
                hash[changed[i]*2] = true;
            }
            else {
                if (hash.find(changed[i]) != hash.end()) continue;
                if (set.find(changed[i]/2) != set.end() && hash.find(changed[i]/2) == hash.end()) {
                    hash[changed[i]/2] = false;
                    hash[changed[i]] = true;
                }
                else if (set.find(changed[i]*2) != set.end() && hash.find(changed[i]*2) == hash.end()) {
                    hash[changed[i]] = false;
                    hash[changed[i]*2] = true;
                }
                else {valid = false; break;}
            }
        }

        if (valid) {
            for (auto x: hash) {
                if (x.second == false) original.push_back(x.first);
            }
        }

        return original;
    }
};