// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int min_size = INT_MAX;
    int sum = 0;
    int i = 0, j = 0;

    while (j < nums.size()) {
      sum += nums[j];
      while (sum >= target) {
        sum -= nums[i];
        min_size = min(min_size, j - i + 1);
        i++;
      }
      j++;
    }

    if (min_size == INT_MAX)
      return 0;
    return min_size;
  }
};
