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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        vector<int> myans;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *p, *nextLevel;
        if (root->left != NULL) nextLevel = root->left;
        else nextLevel = root->right;
        while(!q.empty()) {
            p = q.front();
            q.pop();
            if (p == nextLevel) {
                ans.push_back(myans);
                myans.clear();
                nextLevel = NULL;
            }
            myans.push_back(p->val);
            if (p->left != NULL) {
                q.push(p->left);
                if (nextLevel == NULL) nextLevel = p->left;
            }
            if (p->right != NULL) {
                q.push(p->right);
                if (nextLevel == NULL) nextLevel = p->right;
            }
        }
        ans.push_back(myans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
