/*
 * [1,2,3,1]
 *
 * Think process:
 * position p: std::max(cost[p - 2] + cost, cost[p - 1])
 */
class Solution {
 public:
  int rob(vector<int>& nums) { return maxMoney(nums, nums.size() - 1); }

  int maxMoney(std::vector<int> nums, int p) {
    if (p < 0) return 0;

    return std::max(maxMoney(nums, p - 1), maxMoney(nums, p - 2) + nums[p]);
  }
};
