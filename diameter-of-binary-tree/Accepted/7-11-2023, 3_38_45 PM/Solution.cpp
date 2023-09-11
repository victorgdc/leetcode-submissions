// https://leetcode.com/problems/diameter-of-binary-tree

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
    int diameterOfBinaryTree(TreeNode* root) {
        int max_depth = 0;
        int d = depth(max_depth, root);
        return max_depth;
    }
    int depth (int& max_depth, TreeNode* root) {

        if (root == NULL) return 0;

        int left = depth(max_depth, root->left);
        int right = depth(max_depth, root->right);

        max_depth = max(max_depth, left+right);

        return 1 + max(left, right);
    }
};