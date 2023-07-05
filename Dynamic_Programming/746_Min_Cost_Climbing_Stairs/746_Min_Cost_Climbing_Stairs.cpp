class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    int dp[n];
    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < n; i++) {
      dp[i] = cost[i] + std::min(dp[i - 1], dp[i - 2]);
    }

    return std::min(dp[n - 1], dp[n - 2]);
  }
};
