/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
struct ret {
    bool isValid;
    int count;
    int leftbound, rightbound;
    ret() : isValid(false) {}
    ret(int count, int leftbound, int rightbound) : isValid(true), count(count), leftbound(leftbound), rightbound(rightbound) {}
};

class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        ans = 0;
        if (root) checkSubtree(root);
        return ans;
    }
    
    ret checkSubtree(TreeNode *root) {
        ret left(0, root->val, root->val), right(0, root->val, root->val);
        bool isValid = true;
        if (root->left) {
            left = checkSubtree(root->left);
            if (!left.isValid || left.rightbound >= root->val) isValid = false;
        }
        if (root->right) {
            right = checkSubtree(root->right);
            if (!right.isValid || root->val >= right.leftbound) isValid = false;
        }
        if (!isValid) return ret();
        int count = left.count + right.count + 1;
        ans = max(ans, count);
        return ret(count, left.leftbound, right.rightbound);
    }
    
private:
    int ans;
};
