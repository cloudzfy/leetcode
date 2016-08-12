class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while (s.find(n) == s.end()) {
            s.insert(n);
            int tmpn = n;
            n = 0;
            while (tmpn) {
                int tmp = tmpn % 10;
                tmpn /= 10;
                n += tmp * tmp;
            }
            if (n == 1) return true;
        }
        return false;
    }
};
