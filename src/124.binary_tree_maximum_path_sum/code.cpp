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
    int ans;
public:
    int maxPathSum(TreeNode* root) {
        if (root == NULL) return 0;
        ans = INT_MIN;
        return max(ans, checkTree(root));
    }
    int checkTree(TreeNode* root) {
        if (root->left == NULL && root->right == NULL) return root->val;
        int left = 0, right = 0;
        if (root->left) {
            left = checkTree(root->left);
            ans = max(ans, left);
        }
        if (root->right) {
            right = checkTree(root->right);
            ans = max(ans, right);
        }
        if (root->left != NULL && root->left != NULL) {
            ans = max(ans, left + right + root->val);
            return max(left, right) > 0 ? max(left, right) + root->val : root->val;
        } else if (root->left) {
            return left > 0 ? left + root->val : root->val;
        } else {
            return right > 0 ? right + root->val : root->val;
        }
    }
};
