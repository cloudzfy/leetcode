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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        bool ready = false;
        stack<TreeNode*> s;
        while (root) {
            s.push(root);
            if (root->val < p->val) break;
            root = root->left;
        }
        while (!s.empty()) {
            TreeNode *node = s.top();
            if (ready) return node;
            if (node == p) ready = true;
            s.pop();
            if (node->right) {
                node = node->right;
                while (node) {
                    s.push(node);
                    if (node->val < p->val) break;
                    node = node->left;
                }
            }
        }
        return NULL;
    }
};
