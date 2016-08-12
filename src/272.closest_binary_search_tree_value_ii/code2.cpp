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
    stack<TreeNode*> pre, suc;
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> ans;
        if (root == NULL) return ans;
        initializePredecessor(root, target);
        initializeSuccessor(root, target);
        if (!pre.empty() && !suc.empty() && pre.top() == suc.top()) {
            getPredecessor();
        }
        while (k--) {
            if (pre.empty()) {
                ans.push_back(getSuccessor());
            } else if (suc.empty()) {
                ans.push_back(getPredecessor());
            } else {
                if (target - pre.top()->val < suc.top()->val - target) {
                    ans.push_back(getPredecessor());
                } else {
                    ans.push_back(getSuccessor());
                }
            }
        }
        return ans;
    }
    
    void initializePredecessor(TreeNode* root, double target) {
        while (root) {
            if (root->val == target) {
                pre.push(root);
                break;
            } else if (root->val < target) {
                pre.push(root);
                root = root->right;
            } else {
                root = root->left;
            }
        }
    }
    
    void initializeSuccessor(TreeNode* root, double target) {
        while (root) {
            if (root->val == target) {
                suc.push(root);
                break;
            } else if (root->val > target) {
                suc.push(root);
                root = root->left;
            } else {
                root = root->right;
            }
        }
    }
    
    int getPredecessor() {
        TreeNode* cur = pre.top();
        pre.pop();
        int val = cur->val;
        cur = cur->left;
        while (cur) {
            pre.push(cur);
            cur = cur->right;
        }
        return val;
    }
    
    int getSuccessor() {
        TreeNode * cur = suc.top();
        suc.pop();
        int val = cur->val;
        cur = cur->right;
        while (cur) {
            suc.push(cur);
            cur = cur->left;
        }
        return val;
    }
};
