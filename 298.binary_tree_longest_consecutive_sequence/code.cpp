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
    int longestConsecutive(TreeNode* root) {
        if (root == NULL) return 0;
        return checkTree(root, 0);
    }
    int checkTree(TreeNode* root, int myans) {
        int ans = myans + 1;
        if (root->left) {
            if (root->val + 1 == root->left->val) ans = max(ans, checkTree(root->left, myans + 1));
            else ans = max(ans, checkTree(root->left, 0));
        }
        if (root->right) {
            if (root->val + 1 == root->right->val) ans = max(ans, checkTree(root->right, myans + 1));
            else ans = max(ans, checkTree(root->right, 0));
        }
        return ans;
    }
};
