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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;
        return makeTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
    TreeNode* makeTree(vector<int>::iterator pFirst, vector<int>::iterator pLast, vector<int>::iterator iFirst, vector<int>::iterator iLast) {
        if (pFirst == pLast) return NULL;
        if (iFirst == iLast) return NULL;
        TreeNode* node = new TreeNode(*pFirst);
        vector<int>::iterator root = find(iFirst, iLast, *pFirst);
        int dis = root - iFirst;
        node->left = makeTree(pFirst + 1, pFirst + dis + 1, iFirst, root);
        node->right = makeTree(pFirst + dis + 1, pLast, root + 1, iLast);
        return node;
    }
};
