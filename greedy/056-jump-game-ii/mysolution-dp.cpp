class Solution {
public:
  int jump(vector<int> &nums) {
    assert(nums.size() >= 1 && nums.size() <= 1e4);

    vector<int> dp(nums.size(), INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < nums.size(); i++) {
      // printf("DD\n");
      for (int j = j; j < nums.size() && j <= i + nums[i]; j++) {
        dp[j] = min(dp[i] + 1, dp[j]);
        // printf("dp[%d] - %d\n", j, dp[j]);
      }
    }
    return dp[nums.size() - 1];
  }
};
