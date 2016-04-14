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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode *p = root;
        while (p) {
            s.push(p);
            p = p->left;
        }
        while (!s.empty()) {
            p = s.top();
            s.pop();
            if (--k == 0) return p->val;
            if (p->right) {
                p = p->right;
                while (p) {
                    s.push(p);
                    p = p->left;
                }
            }
        }
    }
};
