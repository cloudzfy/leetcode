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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeTree(nums, 0, nums.size());
    }
    TreeNode* makeTree(vector<int>& nums, int begin, int end) {
        if (begin >= end) return NULL;
        int mid = (begin + end) >> 1;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = makeTree(nums, begin, mid);
        root->right = makeTree(nums, mid + 1, end);
        return root;
    }
};
