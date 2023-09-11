// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, bool> stock;
        int nrec = recipes.size();
        int nsupp = supplies.size();
        vector<string> valids;

        for (int i = 0; i < nsupp; i++) {
            stock[supplies[i]] = true;
        }

        for (int i = 0; i < nrec; i++) {
            int ningr = ingredients[i].size();
            int valid = 1;
            for (int j = 0; j < ningr; j++) {
                if (!stock[ingredients[i][j]]) {
                    valid = 0;
                    break;
                }
            }
            if (valid) stock[recipes[i]] = true;  
            else stock[recipes[i]] = false;
        }

        for (int i = 0; i < nrec; i++) {
            if (stock[recipes[i]]) valids.push_back(recipes[i]);
        }
        return valids;
    }
};