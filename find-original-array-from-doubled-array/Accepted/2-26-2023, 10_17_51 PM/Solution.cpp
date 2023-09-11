// https://leetcode.com/problems/find-original-array-from-doubled-array

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        
        if (changed.size() % 2) return vector<int>{};

        vector<int> original;
        unordered_map<int, int> hash;

        for (int i = 0; i < changed.size(); i++) {
            if (hash.find(changed[i]) == hash.end()) hash[changed[i]] = 0;
            hash[changed[i]]++;
        }

        sort(changed.begin(), changed.end());

        for (int i = 0; i < changed.size(); i++) {
            if (changed[i] == 0 && hash[0] >= 2) {
                hash[0] -= 2;
                original.push_back(0);
            }
            else if (changed[i] > 0 && hash[changed[i]] > 0 && hash[changed[i]*2] > 0) {
                hash[changed[i]]--;
                hash[changed[i]*2]--;
                original.push_back(changed[i]);
            } 
        }

        return (original.size() == changed.size()/2) ? original : vector<int>{};
    }
};