// Need practice!
#include <string>
#include <vector>
class Solution {
public:
  int minDistance(std::string word1, std::string word2) {
    const int m = word1.size();
    const int n = word2.size();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    // base condition
    for (int i = 0; i <= m; i++) {
      dp[i][0] = i;
    }
    for (int j = 1; j <= n; j++) {
      dp[0][j] = j;
    }

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (word1[i - 1] == word2[j - 1]) { // dont use `word[i] == word[j]`
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = 1 + std::min({
                             dp[i - 1][j],    /* Delete  */
                             dp[i][j - 1],    /* Insert */
                             dp[i - 1][j - 1] /* Replace */
                         });
        }
      }
    }
    return dp[m][n];
  }
};
