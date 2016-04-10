class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (citations[mid] >= n - mid) {
                if (mid == 0 || citations[mid - 1] < n - mid + 1) return n - mid;
                right = mid - 1;
            } else left = mid + 1;
        }
        return 0;
    }
};
