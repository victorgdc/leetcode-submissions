// https://leetcode.com/problems/course-schedule

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        unordered_map<int, int> indegree;
        stack<int> queue;

        for (int i = 0; i < numCourses; i++) {
            indegree[i] = 0;
        }

        for (int i = 0; i < prerequisites.size(); i++) {
            int ori = prerequisites[i][1];
            int dest = prerequisites[i][0];
            adj[ori].push_back(dest);
            indegree[dest]++;
        }

        for (auto& i: indegree) {
            if (i.second == 0) queue.push(i.first);
        }

        if (queue.empty()) return false;
    
        while(!queue.empty()) {
            int cur = queue.top(); queue.pop();

            for (int i = 0; i < adj[cur].size(); i++) {
                int neighbor = adj[cur][i]; 
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) queue.push(adj[cur][i]);
            } 
        
        }

        for (auto &i: indegree) {
            if (i.second > 0) return false;
        }

        return true;
    }
};