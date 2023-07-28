class Solution {
public:
  double findMaxAverage(vector<int> &nums, int k) {
    assert(k > 0 && k <= nums.size());

    double sum = 0;
    for (int i = 0; i < k; i++) {
      sum += nums[i];
    }
    double max_sum = sum;

    for (int i = 1; i + k - 1 < nums.size(); i++) {
      sum = sum - nums[i - 1] + nums[i + k - 1];
      max_sum = std::max(sum, max_sum);
    }
    return max_sum / k;
  }
};
