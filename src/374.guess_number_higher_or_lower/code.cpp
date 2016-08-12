// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 0, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int ret = guess(mid);
            if (ret == 0) return mid;
            else if (ret == -1) right = mid - 1;
            else if (ret == 1) left = mid + 1;
        }
        return left;
    }
};
