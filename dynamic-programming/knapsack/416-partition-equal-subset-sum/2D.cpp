class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int sum = 0;
    for (const int &num : nums) {
      sum += num;
    }
    if ((sum & 1) == 1)
      return false; // if odd, it is impossible to split

    sum /= 2;

    // initialize
    vector<vector<bool>> dp(nums.size() + 1, vector<int>(sum + 1, false));
    for (int i = 0; i <= nums.size(); i++) {
      dp[i][0] = true;
    }
    for (int j = 1; j <= sum; j++) {
      dp[0][j] = false;
    }

    // 0/1 knapsack problem
    for (int j = 1; j <= sum; j++) {
      for (int i = 1; i <= nums.size(); i++) {
        if (j - nums[i - 1] >= 0) {
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
          /*                              ^ forget to add `-1` here */
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    return dp[nums.size()][sum];
  }
};
