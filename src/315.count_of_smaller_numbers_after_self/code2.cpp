struct BSTNode {
    int val, num, count;
    BSTNode *left, *right;
    BSTNode(int val) : val(val), num(1), count(0), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        if (n == 0) return ans;
        BSTNode *root = new BSTNode(nums[n - 1]);
        ans.push_back(0);
        for (int i = n - 2; i >= 0; i--) {
            BSTNode *p = root;
            int count = 0;
            while (true) {
                if (nums[i] < p->val) {
                    p->count++;
                    if (p->left) p = p->left;
                    else {
                        p->left = new BSTNode(nums[i]);
                        break;
                    }
                } else if (nums[i] > p->val) {
                    count += p->count + p->num;
                    if (p->right) p = p->right;
                    else {
                        p->right = new BSTNode(nums[i]);
                        break;
                    }
                } else {
                    count += p->count;
                    p->num++;
                    break;
                }
            }
            ans.push_back(count);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
