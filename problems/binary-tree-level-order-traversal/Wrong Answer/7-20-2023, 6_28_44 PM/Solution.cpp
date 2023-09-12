// https://leetcode.com/problems/binary-tree-level-order-traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if (root == NULL) return {};

        queue<TreeNode*> q;
        vector<vector<int>> ans;
        unordered_map<int, int> level;
        vector<int> partial;

        int last_level = 0;
        q.push(root);
        level[root->val] = 0;

        while(!q.empty()) {
            TreeNode* tmp = q.front(); q.pop();
            cout << tmp->val << ' ' << level[tmp->val] << ' ' << last_level <<endl;

            if (level[tmp->val] > last_level) {
                ans.push_back(partial);
                partial.clear();
                last_level++;
            }
            partial.push_back(tmp->val);

            if (tmp->left != NULL) {
                q.push(tmp->left);
                level[tmp->left->val] = level[tmp->val] + 1;
            }
            if (tmp->right != NULL) {
                q.push(tmp->right);
                level[tmp->right->val] = level[tmp->val] + 1;
            }
        }
        if (partial.size() > 0) ans.push_back(partial);

        return ans;
    }
};