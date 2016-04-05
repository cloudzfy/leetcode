class Solution {
public:
    bool isHappy(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        unordered_set<int> s;
        int target = n;
        do {
            int tmp = target;
            target = 0;
            while (tmp != 0) {
                target += (tmp % 10) * (tmp % 10);
                tmp /= 10;
            }
            if (s.find(target) != s.end()) return false;
            s.insert(target);
        } while(target != 1);
        return true;
    }
};
