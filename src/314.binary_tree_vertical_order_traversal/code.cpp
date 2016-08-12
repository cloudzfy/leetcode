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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (root == NULL) return vector<vector<int>>();
        int left = 0, right = 0;
        checkWidth(root, 0, left, right);
        vector<vector<int>> ans(right - left + 1, vector<int>());
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, -left));
        while (!q.empty()) {
            TreeNode *p = q.front().first;
            int pos = q.front().second;
            q.pop();
            ans[pos].push_back(p->val);
            if (p->left) q.push(make_pair(p->left, pos - 1));
            if (p->right) q.push(make_pair(p->right, pos + 1));
        }
        return ans;
    }
    void checkWidth(TreeNode* root, int pos, int& left, int& right) {
        if (root->left) checkWidth(root->left, pos - 1, left, right);
        if (root->right) checkWidth(root->right, pos + 1, left, right);
        left = min(left, pos);
        right = max(right, pos);
    }
};
