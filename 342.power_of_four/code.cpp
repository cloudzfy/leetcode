class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num > 0) && (num == (num & (-num))) && !(num & 0xAAAAAAAA);
    }
};
