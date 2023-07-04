class Solution {
 public:
  int rob(vector<int> &nums) {
    int *memo = new int[nums.size()];
    return maxMoney(nums, memo, nums.size() - 1);
  }

  int maxMoney(std::vector<int> nums, int *memo, int p) {
    if (p < 0) return 0;

    if (memo[p] < 0) {
      int result = std::max(maxMoney(nums, memo, p - 1),
                            maxMoney(nums, memo, p - 2) + nums[p]);
      memo[p] = result;
      return result;
    }
    return memo[p];
  }
};
