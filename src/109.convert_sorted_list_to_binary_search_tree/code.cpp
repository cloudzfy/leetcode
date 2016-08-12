/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        for (ListNode* p = head; p != NULL; p = p->next) n++;
        return makeTree(head, 0, n);
    }
    TreeNode* makeTree(ListNode*& head, int start, int end) {
        if (start >= end) return NULL;
        int mid = (start + end) >> 1;
        TreeNode* left = makeTree(head, start, mid);
        TreeNode* root = new TreeNode(head->val);
        head = head->next;
        TreeNode* right = makeTree(head, mid + 1, end);
        root->left = left;
        root->right = right;
        return root;
    }
};
