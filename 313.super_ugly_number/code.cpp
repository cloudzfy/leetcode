class node {
public:
    int value, prime, index;
    node(int value, int prime, int index) : value(value), prime(prime), index(index) {}
};
struct cmp {
    bool operator()(node x, node y) {
        return x.value > y.value;
    }
};
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ans(n, 0);
        ans[0] = 1;
        priority_queue<node, vector<node>, cmp> q;
        for (int i = 0; i < primes.size(); i++) {
            q.push(node(primes[i], primes[i], 1));
        }
        int count = 1;
        int pre = 1;
        while (count < n) {
            do {
                node p = q.top();
                q.pop();
                ans[count] = p.value;
                pre = p.value;
                p.value = p.prime * ans[p.index++];
                q.push(p);
            } while(pre == q.top().value);
            count++;
        }
        return ans[n - 1];
    }
};
