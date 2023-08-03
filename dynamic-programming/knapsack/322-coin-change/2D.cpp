/** Unbounded knapsack problem
 * 
 * Thinking process
 * step 1. check if dp work - y
 * step 2. define state dp[i][j]
 *    i  --> object
 *    j  --> value
 *    dp --> current max coins
 * step 2. find dp transform function
 *    dp[i][j] = max(dp[i][j], 1 + dp[i][j - w[i]])
 * step 3. checking init value
 */
#include <vector>
class Solution {
public:
  int coinChange(std::vector<int> &coins, int amount) {
    const int n = coins.size();
    std::vector<std::vector<int>> dp(n + 1,
                                     std::vector<int>(amount + 1, INT_MAX - 1));

    // initialization
    for (int i = 0; i <= n; i++) {
      dp[i][0] = 0;
    }

    // unbounded knapsack
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= amount; j++) {
        if (j - coins[i - 1] >= 0) {
          dp[i][j] = std::min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    if (dp[n][amount] >= INT_MAX - 1)
      return -1;
    return dp[n][amount];
  }
};