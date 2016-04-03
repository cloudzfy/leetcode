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
    vector<vector<int>> ans;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> myans;
        if (root == NULL) return ans;
        dfs(root, sum, myans);
        return ans;
    }
    void dfs(TreeNode* root, int sum, vector<int>& myans) {
        if (root == NULL) {
            if (sum == 0) ans.push_back(myans);
            return;
        }
        myans.push_back(root->val);
        if (root->left != NULL) {
            dfs(root->left, sum - root->val, myans);
        }
        if (root->right != NULL) {
            dfs(root->right, sum - root->val, myans);
        }
        if (root->left == NULL && root->right == NULL) {
            dfs(root->left, sum - root->val, myans);
        }
        myans.pop_back();
    }
};
