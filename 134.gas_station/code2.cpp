class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, maxSum = INT_MAX, idx = -1;
        int n = gas.size();
        for (int i = 0; i < n; i++) {
            total += gas[i] - cost[i];
            if (total < maxSum) {
                maxSum = total;
                idx = i + 1;
            }
        }
        return total >= 0 ? idx % n : -1;
    }
};
