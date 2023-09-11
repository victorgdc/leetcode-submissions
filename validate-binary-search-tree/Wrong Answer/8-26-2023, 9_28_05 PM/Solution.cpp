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
        
        if (root == NULL) return true;
        if (root->right != NULL && root->right->val < root->val) return false;
        if (root->left != NULL && root->left->val > root->val) return false;

        bool left = isValidBST(root->left);
        bool right = isValidBST(root->right);

        if (left == false || right == false) return false;

        return true;
    }
};