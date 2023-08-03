class Solution {
public:
  int findMaxForm(vector<string> &strs, int m, int n) {
    // dp[i][j] represents the maximum number of strings that can be selected
    // using i 0s and j 1s.
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    for (const auto &str : strs) {
      int count_0 = 0;
      int count_1 = 0;
      for (const char &c : str) {
        if (c == '0')
          count_0++;
        else if (c == '1')
          count_1++;
      }

      for (int i = m; i >= count_0; i--) {
        for (int j = n; j >= count_1; j--) {
          if (i - count_0 >= 0 && j - count_1 >= 0)
            dp[i][j] = max(dp[i][j], 1 + dp[i - count_0][j - count_1]);
        }
      }
    }
    return dp[m][n];
  }
};
