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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        if (root == NULL) return ans;
        TreeNode* p = root;
        s.push(root);
        while (!s.empty()) {
            while (p != NULL && p->left != NULL) {
                s.push(p->left);
                p = p->left;
            }
            p = s.top();
            ans.push_back(p->val);
            s.pop();
            if (p->right != NULL) {
                s.push(p->right);
                p = p->right;
            } else p = NULL;
        }
        return ans;
    }
};
