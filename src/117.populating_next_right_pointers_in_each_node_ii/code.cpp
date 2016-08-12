/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *p = root;
        TreeLinkNode *pre = NULL;
        TreeLinkNode *nextLevel = NULL;
        while (p) {
            if (p->left) {
                if (pre) pre->next = p->left;
                pre = p->left;
                if (!nextLevel) nextLevel = p->left;
            }
            if (p->right) {
                if (pre) pre->next = p->right;
                pre = p->right;
                if (!nextLevel) nextLevel = p->right;
            }
            p = p->next;
        }
        if (nextLevel) connect(nextLevel);
    }
};
