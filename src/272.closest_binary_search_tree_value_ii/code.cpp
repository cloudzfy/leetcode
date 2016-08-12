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
    stack<int> pre, suc;
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> ans;
        if (root == NULL) return ans;
        initializePreStack(root, target);
        initializeSucStack(root, target);
        while (k--) {
            if (pre.empty()) {
                ans.push_back(suc.top());
                suc.pop();
            } else if (suc.empty()) {
                ans.push_back(pre.top());
                pre.pop();
            } else {
                if (target - pre.top() < suc.top() - target) {
                    ans.push_back(pre.top());
                    pre.pop();
                } else {
                    ans.push_back(suc.top());
                    suc.pop();
                }
            }
        }
        return ans;
    }
    void initializePreStack(TreeNode* root, double target) {
        if (root->left) initializePreStack(root->left, target);
        if (root->val <= target) pre.push(root->val);
        else return;
        if (root->right) initializePreStack(root->right, target);
    }
    
    void initializeSucStack(TreeNode* root, double target) {
        if (root->right) initializeSucStack(root->right, target);
        if (root->val > target) suc.push(root->val);
        else return;
        if (root->left) initializeSucStack(root->left, target);
    }
};
