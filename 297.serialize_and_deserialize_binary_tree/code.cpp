/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        if (root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        ans += numToStr(root->val);
        while (!q.empty()) {
            TreeNode *p = q.front();
            q.pop();
            if (p->left) {
                q.push(p->left);
                ans += "," + numToStr(p->left->val);
            } else {
                ans += ",null";
            }
            if (p->right) {
                q.push(p->right);
                ans += "," + numToStr(p->right->val);
            } else {
                ans += ",null";
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 0) return NULL;
        queue<TreeNode*> q;
        int index = 0;
        string elem = subStr(data, index);
        TreeNode *root = new TreeNode(strToNum(elem));
        q.push(root);
        while (!q.empty()) {
            TreeNode *p = q.front();
            q.pop();
            elem = subStr(data, index);
            if (elem != "null") {
                p->left = new TreeNode(strToNum(elem));
                q.push(p->left);
            }
            elem = subStr(data, index);
            if (elem != "null") {
                p->right = new TreeNode(strToNum(elem));
                q.push(p->right);
            }
        }
        return root;
    }
    
    string numToStr(int num) {
        char str[20];
        sprintf(str, "%d", num);
        return str;
    }
    
    int strToNum(string str) {
        int num = 0;
        int i = 0;
        int sign = 1;
        if (str[0] == '-') {
            sign = -1;
            i++;
        }
        while (i < str.length()) {
            num *= 10;
            num += str[i] - '0';
            i++;
        }
        return sign * num;
    }
    
    string subStr(string data, int& index) {
        int start = index;
        while (data[index] != ',' && data[index] != 0) index++;
        return data.substr(start, index++ - start);
    } 
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
