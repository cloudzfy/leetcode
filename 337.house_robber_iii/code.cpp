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
    int rob(TreeNode* root) {
        if (root == NULL) return 0;
        int pre = 0, cur = 0;
        dfs(root, pre, cur);
        return max(pre, cur);
    }
    int dfs(TreeNode* root, int& pre, int& cur) {
        int leftPre = 0, leftCur = 0;
        int rightPre = 0, rightCur = 0;
        if (root->left) dfs(root->left, leftPre, leftCur);
        if (root->right) dfs(root->right, rightPre, rightCur);
        pre = max(leftPre, leftCur) + max(rightPre, rightCur);
        cur = leftPre + rightPre + root->val;
    }
};
