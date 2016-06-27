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
    vector<vector<int>> findLeaves(TreeNode* root) {
        if (root) dfs(root);
        return ans;
    }
    
    int dfs(TreeNode *root) {
        int left = -1, right = -1;
        if (root->left) left = dfs(root->left);
        if (root->right) right = dfs(root->right);
        int idx = max(left, right) + 1;
        if (ans.size() == idx) ans.push_back({});
        ans[idx].push_back(root->val);
        return idx;
    }
    
private:
    vector<vector<int> > ans;
};
