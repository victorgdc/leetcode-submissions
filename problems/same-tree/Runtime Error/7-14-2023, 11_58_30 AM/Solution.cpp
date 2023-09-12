// https://leetcode.com/problems/same-tree

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true;

        if (p->val != q->val) return false;

        if ((p->left != NULL && q->left != NULL) && 
        (p->left->val != q->left->val)) return false;
        else if ((p->left == NULL && q->left != NULL) || 
        (p->left != NULL && q->left == NULL)) return false;
        
        if ((p->right != NULL && q->right != NULL) && 
        (p->right->val != q->right->val)) return false;
        else if ((p->right == NULL && q->right != NULL) || 
        (p->right != NULL && q->right == NULL)) return false;

        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);

        return (left == false || right == false) ? false : true;
    }
};