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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        stack<pair<TreeNode*, bool> > s;
        s.push(make_pair(root, false));
        while (!s.empty()) {
            TreeNode *p = s.top().first;
            bool visited = s.top().second;
            s.pop();
            if (!visited) {
                s.push(make_pair(p, true));
                if (p->right) s.push(make_pair(p->right, false));
                if (p->left) s.push(make_pair(p->left, false));
            } else {
                ans.push_back(p->val);
            }
        }
        return ans;
    }
};
