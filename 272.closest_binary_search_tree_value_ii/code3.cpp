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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        stack<TreeNode*> predecessors;
        stack<TreeNode*> successors;
        while (root) {
            if (root->val < target) {
                predecessors.push(root);
                root = root->right;
            } else {
                successors.push(root);
                root = root->left;
            }
        }
        vector<int> ans;
        while (k--) {
            if (predecessors.empty()) {
                ans.push_back(getSuccessors(successors));
            } else if (successors.empty()) {
                ans.push_back(getPredecessors(predecessors));
            } else {
                if (fabs(target - predecessors.top()->val) < fabs(target - successors.top()->val)) {
                    ans.push_back(getPredecessors(predecessors));
                } else {
                    ans.push_back(getSuccessors(successors));
                }
            }
        }
        return ans;
    }
    
    int getPredecessors(stack<TreeNode*> &predecessors) {
        TreeNode *p = predecessors.top();
        predecessors.pop();
        int val = p->val;
        if (p->left) {
            p = p->left;
            while (p) {
                predecessors.push(p);
                p = p->right;
            }
        }
        return val;
    }
    
    int getSuccessors(stack<TreeNode*> &successors) {
        TreeNode *p = successors.top();
        successors.pop();
        int val = p->val;
        if (p->right) {
            p = p->right;
            while (p) {
                successors.push(p);
                p = p->left;
            }
        }
        return val;
    }
};
