// Space Complex: O(N^2) --> too large

/* Think:
    1. Define state:
        dp[i] is the minimal path sum from root

    2. Transformation function:
        dp[i] = dp[i] + min(triangle[level][i], triangle[level][i + 1])

    3. start and boundaries
    4. return value
 */

#include <algorithm>
#include <cassert>
#include <vector>
class Solution {
public:
  int minimumTotal(std::vector<std::vector<int>> &triangle) {
    assert(triangle.size());

    int h = triangle.size();
    std::vector<std::vector<int>> dp(h, std::vector<int>());

    dp[0].emplace_back(triangle[0][0]);

    for (int l = 1; l < h; l++) {
      for (int i = 0; i < l + 1; i++) {
        if (i == 0) {
          dp[l].emplace_back(triangle[l][0] + dp[l - 1][0]);
        } else if (i == l) {
          dp[l].emplace_back(triangle[l][i] + dp[l - 1][i - 1]);
        } else {
          const int tmp =
              triangle[l][i] + std::min(dp[l - 1][i - 1], dp[l - 1][i]);
          dp[l].emplace_back(tmp);
        }
      }
    }
    return *std::min_element(dp.back().begin(), dp.back().end());
  }
};
