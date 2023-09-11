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
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        
        if (root == NULL) return ans;

        q.push(root);

        vector<int> partial;
        
        while(!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* tmp = q.front(); q.pop();

                if (tmp->left != NULL) q.push(tmp->left);
                if (tmp->right != NULL) q.push(tmp->right);

                partial.push_back(tmp->val);
            }    
            ans.push_back(partial);
            partial.clear();
        }

        return ans;
    }
};