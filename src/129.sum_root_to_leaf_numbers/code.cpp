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
    int sumNumbers(TreeNode* root) {
        if (root == NULL) return 0;
        return dfs(root, 0);
    }
    int dfs(TreeNode* root, int num) {
        int ans = 0;
        num = num * 10 + root->val;
        if (root->left) ans += dfs(root->left, num);
        if (root->right) ans += dfs(root->right, num);
        if (root->left == NULL && root->right == NULL) {
            ans += num;
        }
        return ans;
    }
};
