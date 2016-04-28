/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Info {
public:
    int minVal;
    int maxVal;
    int size;
    int isBST;
    Info() : minVal(INT_MAX), maxVal(INT_MIN), size(0), isBST(false) {}
};
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        int ans = 0;
        searchBSTSubtree(root, ans);
        return ans;
    }
    
    Info searchBSTSubtree(TreeNode* root, int& ans) {
        Info curInfo, leftInfo, rightInfo;
        if (root == NULL) {
            curInfo.isBST = true;
            return curInfo;
        }
        leftInfo = searchBSTSubtree(root->left, ans);
        rightInfo = searchBSTSubtree(root->right, ans);
        curInfo.minVal = min(leftInfo.minVal, root->val);
        curInfo.maxVal = max(rightInfo.maxVal, root->val);
        curInfo.size = leftInfo.size + rightInfo.size + 1;
        if (leftInfo.isBST && rightInfo.isBST) {
            if (leftInfo.maxVal < root->val && root->val < rightInfo.minVal) {
                curInfo.isBST = true;
                ans = max(ans, curInfo.size);
            }
        }
        return curInfo;
    }
};
