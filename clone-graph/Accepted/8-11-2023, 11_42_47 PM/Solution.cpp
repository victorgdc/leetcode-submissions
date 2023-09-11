// https://leetcode.com/problems/clone-graph

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return node;
        
        unordered_map<Node*, Node*> map;
        queue<Node*> q;
        Node* head = new Node(node->val, {});

        q.push(node);
        map[node] = head;

        while(!q.empty()) {
            Node* cur = q.front(); q.pop();
        
            for (int i = 0; i < cur->neighbors.size(); i++) {
                
                if (map.find(cur->neighbors[i]) == map.end()) {
                    map[cur->neighbors[i]] = new Node(cur->neighbors[i]->val, {});
                    q.push(cur->neighbors[i]);
                }
                map[cur]->neighbors.push_back(map[cur->neighbors[i]]);
            }
        }


        return map[node];
    }
};