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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        return checkPathSum(root, sum);
    }
    bool checkPathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            if (sum == 0) return true;
            return false;
        }
        if (root->left == NULL) return checkPathSum(root->right, sum - root->val);
        if (root->right == NULL) return checkPathSum(root->left, sum - root->val);
        return checkPathSum(root->left, sum - root->val) || checkPathSum(root->right, sum - root->val);
    }
};
