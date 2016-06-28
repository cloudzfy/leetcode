class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return z == 0 || (z <= x + y && z % gcd(x, y) == 0);
    }
    
    int gcd(int x, int y) {
        while (y) {
            int tmp = x % y;
            x = y;
            y = tmp;
        }
        return x;
    }
};
