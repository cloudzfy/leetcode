class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int limit = INT_MIN;
        int top = 0;
        for (int i = 0; i < preorder.size(); i++) {
            while (top > 0 && preorder[top - 1] < preorder[i]) {
                top--;
                limit = preorder[top];
            }
            if (limit > preorder[i]) return false;
            swap(preorder[i], preorder[top++]);
        }
        return true;
    }
};
