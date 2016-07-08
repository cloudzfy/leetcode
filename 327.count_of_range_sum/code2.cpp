struct BSTNode {
    long long val;
    int num, count;
    BSTNode *left, *right;
    BSTNode(long long val) : val(val), num(1), count(0), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long long sum = 0;
        BSTNode *root = new BSTNode(0);
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            BSTNode *p = root;
            long long lowerCount = 0, upperCount = 0;
            while (p) {
                if (sum - upper < p->val) p = p->left;
                else if (sum - upper > p->val) {
                    lowerCount += p->count + p->num;
                    p = p->right;
                } else {
                    lowerCount += p->count;
                    break;
                }
            }
            p = root;
            while (p) {
                if (sum - lower < p->val) p = p->left;
                else if (sum - lower > p->val) {
                    upperCount += p->count + p->num;
                    p = p->right;
                } else {
                    upperCount += p->count + p->num;
                    break;
                }
            }
            ans += upperCount - lowerCount;
            p = root;
            while (p) {
                if (sum < p->val) {
                    p->count++;
                    if (p->left) p = p->left;
                    else {
                        p->left = new BSTNode(sum);
                        break;
                    }
                } else if (sum > p->val) {
                    if (p->right) p = p->right;
                    else {
                        p->right = new BSTNode(sum);
                        break;
                    }
                } else {
                    p->num++;
                    break;
                }
            }
        }
        return ans;
    }
};
