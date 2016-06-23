/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        stack<pair<NestedInteger, int> > s;
        for (int i = 0; i < nestedList.size(); i++) {
            s.push(make_pair(nestedList[i], 1));
        }
        int height = 1;
        while (!s.empty()) {
            NestedInteger u = s.top().first;
            int depth = s.top().second;
            s.pop();
            height = max(height, depth);
            if (!u.isInteger()) {
                vector<NestedInteger> m = u.getList();
                for (int i = 0; i < m.size(); i++) {
                    s.push(make_pair(m[i], depth + 1));
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < nestedList.size(); i++) {
            s.push(make_pair(nestedList[i], height));
        }
        while (!s.empty()) {
            NestedInteger u = s.top().first;
            int depth = s.top().second;
            s.pop();
            if (u.isInteger()) {
                ans += u.getInteger() * depth;
            } else {
                vector<NestedInteger> m = u.getList();
                for (int i = 0; i < m.size(); i++) {
                    s.push(make_pair(m[i], depth - 1));
                }
            }
        }
        return ans;
    }
};
