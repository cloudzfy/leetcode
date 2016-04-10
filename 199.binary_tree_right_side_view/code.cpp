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
    vector<int> ans;
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) return ans;
        checkTree(root, 0);
        return ans;
    }
    void checkTree(TreeNode* root, int depth) {
        if (ans.size() < depth + 1) ans.push_back(root->val);
        else ans[depth] = root->val;
        if (root->left) checkTree(root->left, depth + 1);
        if (root->right) checkTree(root->right, depth + 1);
    }
};
