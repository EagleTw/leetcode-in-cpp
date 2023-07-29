class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int max_sum = INT_MIN;
    int sum = 0;

    for (const auto &num : nums) {
      if (sum < 0)
        sum = 0;
      sum += num;
      max_sum = max(sum, max_sum);
    }
    return max_sum;
  }
};
