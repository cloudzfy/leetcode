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
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        int leftHeight = 0, rightHeight = 0;
        int ans = 0;
        while (root) {
            if (!leftHeight) {
                for (TreeNode *p = root->left; p != NULL; p = p->left) leftHeight++;
            }
            if (!rightHeight) {
                for (TreeNode *p = root->right; p != NULL; p = p->left) rightHeight++;
            }
            if (leftHeight == rightHeight) {
                ans += (1 << leftHeight);
                leftHeight = rightHeight - 1;
                rightHeight = 0;
                root = root->right;
            } else {
                ans += (1 << rightHeight);
                leftHeight--;
                rightHeight = 0;
                root = root->left;
            }
        }
        return ans;
    }
};
