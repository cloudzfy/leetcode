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
    bool isSymmetric(TreeNode* root) {
        stack<TreeNode*> s1, s2;
        if (root == NULL) return true;
        TreeNode *p1, *p2;
        s1.push(root->left);
        s2.push(root->right);
        while(!s1.empty() && !s2.empty()) {
            p1 = s1.top();
            s1.pop();
            p2 = s2.top();
            s2.pop();
            if (p1 != NULL && p2 == NULL) return false;
            if (p1 == NULL && p2 != NULL) return false;
            if (p1 != NULL && p2 != NULL) {
                if (p1->val != p2->val) return false;
                s1.push(p1->left);
                s2.push(p2->right);
                s1.push(p1->right);
                s2.push(p2->left);
            }
        }
        return true;
    }
};
