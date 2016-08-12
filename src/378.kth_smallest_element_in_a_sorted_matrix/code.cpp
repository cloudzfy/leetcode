struct node {
    int x, y, val;
    node(int x, int y, int val) : x(x), y(y), val(val) {}
};

struct cmp {
    bool operator()(const node &a, const node &b) {
        return a.val > b.val;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<node, vector<node>, cmp> pq;
        if (n == 0) return 0;
        int ans = matrix[0][0];
        pq.push(node(0, 0, matrix[0][0]));
        for (int i = 0; i < k; i++) {
            node cur = pq.top();
            pq.pop();
            ans = cur.val;
            if (cur.x + 1 < n && cur.y == 0) {
                pq.push(node(cur.x + 1, cur.y, matrix[cur.x + 1][cur.y]));
            }
            if (cur.y + 1 < n) {
                pq.push(node(cur.x, cur.y + 1, matrix[cur.x][cur.y + 1]));
            }
        }
        return ans;
    }
};
