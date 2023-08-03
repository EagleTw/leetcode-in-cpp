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
    vector<bool> dp(sum + 1, false);
    dp[0] = true;

    // 0/1 knapsack problem
    for (int i = 0; i < nums.size(); i++) { // range changed
      for (int j = sum; j >= 0; j--) {      // going backward
        if (j - nums[i] >= 0) {
          dp[j] = dp[j] || dp[j - nums[i]];
        }
      }
    }
    return dp[sum];
  }
};
