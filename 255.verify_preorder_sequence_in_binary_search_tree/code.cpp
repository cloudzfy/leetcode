class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> s;
        int limit = INT_MIN;
        for (int i = 0; i < preorder.size(); i++) {
            while (!s.empty() && s.top() < preorder[i]) {
                limit = s.top();
                s.pop();
            }
            if (preorder[i] < limit) return false;
            s.push(preorder[i]);
        }
        return true;
    }
};
