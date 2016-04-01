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
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        return checkBST(root, NULL, NULL);
    }
    bool checkBST(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (min != NULL && min->val >= root->val) return false;
        if (max != NULL && root->val >= max->val) return false;
        if (root->left != NULL && !checkBST(root->left, min, root)) return false;
        if (root->right != NULL && !checkBST(root->right, root, max)) return false;
        return true;
        
    }
};
