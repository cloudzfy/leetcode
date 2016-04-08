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
        if (root == NULL) return ans;
        unordered_map<TreeNode*, bool> visited;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* p = s.top();
            if (p->left == NULL && p->right == NULL) {
                s.pop();
                ans.push_back(p->val);
                continue;
            }
            if (visited.find(p) != visited.end()) {
                s.pop();
                ans.push_back(p->val);
                continue;
            }
            else visited[p] = true;
            if (p->right) s.push(p->right);
            if (p->left) s.push(p->left);
        }
        return ans;
    }
};
