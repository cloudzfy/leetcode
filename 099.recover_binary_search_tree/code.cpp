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
    TreeNode *pre;
    TreeNode *mistake1, *mistake2;
public:
    void recoverTree(TreeNode* root) {
        pre = NULL;
        mistake1 = mistake2 = NULL;
        inorder(root);
        swap(mistake1->val, mistake2->val);
    }
    void inorder(TreeNode* root) {
        if (root->left) inorder(root->left);
        if (pre != NULL && pre->val > root->val) {
            if (mistake1 == NULL) mistake1 = pre;
            mistake2 = root;
        }
        pre = root;
        if (root->right) inorder(root->right);
    }
};
