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
    int countUnivalSubtrees(TreeNode* root) {
        int ans = 0;
        isUnivalSubtree(root, ans);
        return ans;
    }
    bool isUnivalSubtree(TreeNode* root, int& ans) {
        if (root == NULL) return true;
        bool left = isUnivalSubtree(root->left, ans);
        bool right = isUnivalSubtree(root->right, ans);
        if (left && right) {
            if (root->left && root->val != root->left->val) return false;
            if (root->right && root->val != root->right->val) return false;
            ans++;
            return true;
        }
        return false;
    }
};
