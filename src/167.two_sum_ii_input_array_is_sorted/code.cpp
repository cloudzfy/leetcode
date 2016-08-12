class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            while (left < right && numbers[left] + numbers[right] < target) left++;
            if (numbers[left] + numbers[right] == target) {
                return vector<int>({left + 1, right + 1});
            }
            while (left < right && numbers[left] + numbers[right] > target) right--;
            if (numbers[left] + numbers[right] == target) {
                return vector<int>({left + 1, right + 1});
            }
        }
        return vector<int>();
    }
};
