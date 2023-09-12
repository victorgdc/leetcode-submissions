// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {

        unordered_map<string, vector<string>> graph;
        unordered_set<string> stock;
        unordered_map<string, int> indegree;
        vector<string> answer;
        int nrec = recipes.size();

        for (auto x : supplies) stock.insert(x);
        for (auto x : recipes) indegree[x] = 0;

        for (int i = 0; i < nrec; i++) {
            for (int j = 0; j < ingredients[i].size(); j++) {
                if (stock.find(ingredients[i][j]) == stock.end()) {
                    graph[ingredients[i][j]].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
        } 

        queue<string> q;

        for (auto x : recipes) {
            if (indegree[x] == 0) q.push(x);
        }

        while (!q.empty()) {

            string tmp = q.front();
            q.pop();
            answer.push_back(tmp);

            for (auto x: graph[tmp]) {
                indegree[x]--;
                if (indegree[x] == 0) q.push(x);
            }

        }

        return answer;
    }
};