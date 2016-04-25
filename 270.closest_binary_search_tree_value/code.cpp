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
    int closestValue(TreeNode* root, double target) {
        int ans = root->val;
        if (root->left) {
            int val = closestValue(root->left, target);
            ans = fabs((long double)ans - target) > fabs((long double)val - target) ? val : ans;
        }
        if (root->right) {
            int val = closestValue(root->right, target);
            ans = fabs((long double)ans - target) > fabs((long double)val - target) ? val : ans;
        }
        return ans;
    }
};
