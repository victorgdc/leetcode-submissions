// https://leetcode.com/problems/count-words-obtained-after-adding-a-letter

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        
        unordered_set<string> comb;
        int answer = 0;


        for (auto word: startWords) {
            sort(word.begin(), word.end());

            for (char c = 'a'; c <= 'z'; c++) {
                int pos = lower_bound(word.begin(), word.end(), c) - begin(word);

                if (pos == word.size() || word[pos] != c) {
                    comb.insert(word.substr(0, pos) + c + word.substr(pos));
                }
            }
        }

        for (auto x: targetWords) {
            sort(x.begin(), x.end());
            if (comb.find(x) != comb.end()) answer++;
        }

        return answer;

    }
};