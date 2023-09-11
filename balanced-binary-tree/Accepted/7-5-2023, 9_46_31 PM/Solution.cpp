// https://leetcode.com/problems/balanced-binary-tree

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
    bool isBalanced(TreeNode* root) {
        
        return checkDepth(root, 0) == -1 ? false : true;

    }

    int checkDepth(TreeNode* root, int d) {

        if (root == NULL) return 0;
        int dl = checkDepth(root->left, d);
        int dr = checkDepth(root->right, d);
        
        if (dl == -1 || dr == -1 || abs(dl-dr)>1) return -1;
        
        if (dl > dr) return dl+1;
        else return dr+1;

    }

};