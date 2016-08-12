/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (root && root->left) {
            TreeNode *p = upsideDownBinaryTree(root->left);
            root->left->left = root->right;
            root->left->right = root;
            root->left = NULL;
            root->right = NULL;
            return p;
        }
        return root;
    }
};
