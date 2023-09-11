// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies

class Solution {
public:
    bool checkRecipe(string recipe, vector<vector<string>> ingr, unordered_map<string, bool> & stock, unordered_map<string, int>& menu) {
        
        bool valid;
        int index = menu[recipe];

        for (int i = 0; i < ingr[index].size(); i++) {
            valid = true;
            if (menu.find(ingr[index][i]) == menu.end()) {
                if (stock[ingr[index][i]] != true) {
                    valid = false;
                    break;
                }
            }
            else { // The ingredient is a recipe
                if (stock.find(ingr[index][i]) == stock.end()) { // If the recipe wasnt made yet
                    stock[ingr[index][i]] = checkRecipe(ingr[index][i], ingr, stock, menu); 
                    if (!stock[ingr[index][i]]) {
                        valid = false;
                        break;
                    }
                }
                else {
                    if (stock[ingr[index][i]] != true) {
                        valid = false;
                        break;
                    }
                }
            }
        }

        return valid;
    }

    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, bool> stock;
        unordered_map<string, int> menu;
        int nrec = recipes.size();
        int nsupp = supplies.size();
        vector<string> valids;

        for (int i = 0; i < nsupp; i++) {
            stock[supplies[i]] = true;
        }

        for (int i = 0; i < nrec; i++) {
            menu[recipes[i]] = i;
        }

        for (int i = 0; i < nrec; i++) {
            stock[recipes[i]] = checkRecipe(recipes[i], ingredients, stock, menu);
        }

        for (int i = 0; i < nrec; i++) {
            if (stock[recipes[i]]) valids.push_back(recipes[i]);
        }

        return valids;
    }
};