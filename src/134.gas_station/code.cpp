class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int left = n, right = n;
        int sum = 0;
        while (right - left < n) {
            if (sum > 0) {
                sum += gas[right % n] - cost[right % n];
                right++;
            } else {
                left--;
                sum += gas[left % n] - cost[left % n];
            }
        }
        if (sum >= 0) return left;
        return -1;
    }
};
