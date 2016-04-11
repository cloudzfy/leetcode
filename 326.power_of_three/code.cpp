class Solution {
public:
    bool isPowerOfThree(int n) {
        double num = log(n) / log(3);
        return abs(num - round(num)) <= 1e-12;
    }
};
