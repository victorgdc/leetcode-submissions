// https://leetcode.com/problems/count-words-obtained-after-adding-a-letter

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        
        vector<bool> valid(targetWords.size(), false);
        int result = 0;

        for (int i = 0; i < startWords.size(); i++) {

            unordered_set<char> alph;
            for (auto c: startWords[i]) alph.insert(c);

            for (int j = 0; j < targetWords.size(); j++) {
                if (valid[j] == true) continue;
                int count = 0;
                for (auto x: targetWords[j]) {
                    if (alph.find(x) == alph.end()) count++;
                    if (count == 2) break;
                }

                if (count == 1 && startWords[i].size() < targetWords[j].size()) {result++; valid[j] = true;}
                
                continue;
            }

            if (result == targetWords.size()) break;

        }

        return result;
    }
};