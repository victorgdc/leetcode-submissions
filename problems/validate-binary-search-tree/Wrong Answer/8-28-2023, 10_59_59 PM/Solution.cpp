// https://leetcode.com/problems/validate-binary-search-tree

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
    bool isValidBST(TreeNode* root) {
        return valid(root, -1e5, 1e5);
    }

    bool valid(TreeNode* root, int left, int right) {
        if (root == NULL) return true;

        if (root->val <= left || root->val >= right) return false;

        return valid(root->left, left, root->val) && valid(root->right, root->val, right); 
    }

};