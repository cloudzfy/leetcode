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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> myans;
        if (root == NULL) return ans;
        queue<TreeNode*> q;
        TreeNode *p, *next;
        q.push(root);
        if (root->left != NULL) next = root->left;
        else next = root->right;
        while(!q.empty()) {
            p = q.front();
            q.pop();
            if (p == next) {
                ans.push_back(myans);
                next = NULL;
                myans.clear();
            }
            myans.push_back(p->val);
            if (p->left != NULL) {
                q.push(p->left);
                if (next == NULL) next = p->left;
            }
            if (p->right != NULL) {
                q.push(p->right);
                if (next == NULL) next = p->right;
            }
        }
        ans.push_back(myans);
        return ans;
    }
};
