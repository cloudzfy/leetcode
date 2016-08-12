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
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);
        if (leftDepth > 0 && rightDepth > 0) return min(leftDepth, rightDepth) + 1;
        if (leftDepth > 0) return leftDepth + 1;
        if (rightDepth > 0) return rightDepth + 1;
        return 1;
    }
};
