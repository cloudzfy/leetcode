struct cmp {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        return a.first + a.second < b.first + b.second;
    }
};

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for (int i = 0; i < min(n1, k); i++) {
            for (int j = 0; j < min(n2, k); j++) {
                if (pq.size() < k) {
                    pq.push(make_pair(nums1[i], nums2[j]));
                } else if (nums1[i] + nums2[j] < pq.top().first + pq.top().second) {
                    pq.push(make_pair(nums1[i], nums2[j]));
                    pq.pop();
                }
            }
        }
        vector<pair<int, int> > ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
