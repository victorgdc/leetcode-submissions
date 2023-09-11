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

        if (root->left != NULL) {
            int max = 0;
            maxValue(root->left, max);
            if (max >= root->val) return false;
        }
        if (root->right != NULL) {
            int min = 1e5;
            minValue(root->right, min);
            if (min <= root->val) return false;
        }

        return true;
    }
    void maxValue(TreeNode* root, int& val) {
        if (root == NULL) return;
        if (root->val > val) val = root->val;

        maxValue(root->left, val);
        maxValue(root->right, val);
    }
    void minValue(TreeNode* root, int& val) {
        if (root == NULL) return;
        if (root->val < val) {
            val = root->val;
        }

        minValue(root->left, val);
        minValue(root->right, val);
    }
};