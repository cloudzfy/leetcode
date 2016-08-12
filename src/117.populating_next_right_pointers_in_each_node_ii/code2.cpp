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
        if (!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            TreeLinkNode *p = q.front();
            q.pop();
            if (!p) {
                if (!q.empty()) q.push(NULL);
                continue;
            }
            p->next = q.front();
            if (p->left) q.push(p->left);
            if (p->right) q.push(p->right);
        }
    }
};
