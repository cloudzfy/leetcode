/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        NestedInteger ans;
        int num = 0;
        bool hasNum = false;
        int sign = 1;
        if (s[0] != '[') {
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == '-') sign = -1;
                else {
                    num *= 10;
                    num += s[i] - '0';
                }
            }
            ans.setInteger(sign * num);
            return ans;
        }
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '-') {
                sign = -1;
            } else if (s[i] <= '9' && s[i] >= '0') {
                num *= 10;
                num += s[i] - '0';
                hasNum = true;
            } else if (hasNum) {
                ans.add(NestedInteger(sign * num));
                num = 0;
                sign = 1;
                hasNum = false;
            } else if (s[i] == '[') {
                int start = i++, count = 1;
                while (count > 0) {
                    if (s[i] == '[') count++;
                    else if (s[i] == ']') count--;
                    i++;
                }
                ans.add(deserialize(s.substr(start, i - start)));
            }
        }
        return ans;
    }
};
