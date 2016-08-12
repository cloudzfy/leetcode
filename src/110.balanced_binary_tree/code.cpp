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
private:
    bool ans;
public:
    bool isBalanced(TreeNode* root) {
        ans = true;
        checkHeight(root);
        return ans;
    }
    int checkHeight(TreeNode* root) {
        if (root == NULL) return 0;
        int leftHeight = checkHeight(root->left);
        int rightHeight = checkHeight(root->right);
        if (abs(leftHeight - rightHeight) > 1) ans = false;
        return max(leftHeight, rightHeight) + 1;
    }
};
