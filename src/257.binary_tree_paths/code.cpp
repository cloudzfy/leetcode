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
    vector<string> ans;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL) return ans;
        string myans;
        dfs(root, myans);
        return ans;
    }
    void dfs(TreeNode* root, string myans) {
        char num[10];
        sprintf(num, "%d", root->val);
        myans = myans + "->" + num;
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(myans.substr(2, myans.length() - 2));
            return;
        }
        if (root->left != NULL) {
            dfs(root->left, myans);
        }
        if (root->right != NULL) {
            dfs(root->right, myans);
        }
    }
};
