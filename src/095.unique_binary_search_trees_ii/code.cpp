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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        if (n == 0) return ans;
        return makeTree(1, n);
    }
    vector<TreeNode*> makeTree(int begin, int end) {
        vector<TreeNode*> myans;
        if (begin > end) {
            myans.push_back(NULL);
            return myans;
        }
        for (int k = begin; k <= end; k++) {
            vector<TreeNode*> left = makeTree(begin, k - 1);
            vector<TreeNode*> right = makeTree(k + 1, end);
            for (int i = 0; i < left.size(); i++) {
                for (int j = 0; j < right.size(); j++) {
                    TreeNode* root = new TreeNode(k);
                    root->left = left[i];
                    root->right = right[j];
                    myans.push_back(root);
                }
            }
        }
        return myans;
    }
};
