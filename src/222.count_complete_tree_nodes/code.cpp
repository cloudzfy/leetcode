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
        TreeNode* p = root;
        int leftHeight = 0, rightHeight = 0;
        while (p) {
            leftHeight++;
            p = p->left;
        }
        p = root;
        while (p) {
            rightHeight++;
            p = p->right;
        }
        if (leftHeight == rightHeight) {
            return (1 << leftHeight) - 1;
        } else {
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }
};
