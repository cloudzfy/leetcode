class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (mid > num / mid) right = mid - 1;
            else if (mid * mid == num) return true;
            else left = mid + 1;
        }
        return false;
    }
};
