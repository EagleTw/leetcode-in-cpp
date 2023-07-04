class Solution {
 public:
  int rob(vector<int> &nums) {
    if (nums.size() - 1 < 0) return 0;
    if (nums.size() == 1) return nums[0];

    std::vector<int> memo(nums.size());
    memo[0] = nums[0];
    memo[1] = std::max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++) {
      memo[i] = std::max(memo[i - 1], memo[i - 2] + nums[i]);
    }
    return memo[nums.size() - 1];
  }
};
