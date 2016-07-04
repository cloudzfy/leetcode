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
    void recoverTree(TreeNode* root) {
        TreeNode *pre = NULL, *mistake1 = NULL, *mistake2 = NULL;
        while (root) {
            if (root->left) {
                TreeNode *p = root->left;
                while (p->right && p->right != root) {
                    p = p->right;
                }
                if (p->right == NULL) {
                    p->right = root;
                    root = root->left;
                } else {
                    p->right = NULL;
                    if (pre != NULL && pre->val > root->val) {
                        if (mistake1 == NULL) mistake1 = pre;
                        mistake2 = root;
                    }
                    pre = root;
                    root = root->right;
                }
            } else {
                if (pre != NULL && pre->val > root->val) {
                    if (mistake1 == NULL) mistake1 = pre;
                    mistake2 = root;
                }
                pre = root;
                root = root->right;
            }
        }
        swap(mistake1->val, mistake2->val);
    }
};
