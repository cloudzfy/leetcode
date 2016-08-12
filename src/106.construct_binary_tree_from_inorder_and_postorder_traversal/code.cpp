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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return makeTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
    TreeNode* makeTree(vector<int>::iterator iFirst, vector<int>::iterator iLast, vector<int>::iterator pFirst, vector<int>::iterator pLast) {
        if (iFirst == iLast) return NULL;
        if (pFirst == pLast) return NULL;
        int val = *(pLast - 1);
        TreeNode* root = new TreeNode(val);
        vector<int>::iterator iRoot = find(iFirst, iLast, val);
        int dis = iRoot - iFirst;
        root->left = makeTree(iFirst, iRoot, pFirst, pFirst + dis);
        root->right = makeTree(iRoot + 1, iLast, pFirst + dis, pLast - 1);
        return root;
    }
};
