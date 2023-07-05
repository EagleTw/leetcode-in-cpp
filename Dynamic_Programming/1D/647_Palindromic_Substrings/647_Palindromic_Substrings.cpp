/*
 * Example:
 * index: 0 1 2 3 4 5
 *      " a a a b b a "
 *
 * Step 1. Create a table
 * Step 2. Diagnal self is palindromic string
 *
 *   | 0 1 2 3 4 5 <-- ending position
 * --+---------------
 * 0 | 1 2
 * 1 |   1 2
 * 2 |     1 0
 * 3 |       1 2
 * 4 |         1 0
 * 5 |           1
 * ^
 * | starting position
 *
 *
 * Step 3: starting looping
 *    [start, end] is palindromic if (1) s[start] == s[end]
 *                                   (2) [start + 1, end - 1] is palindromic
 *
 *   | 0 1 2 3 4 5 <-- ending position
 * --+---------------
 * 0 | 1 2
 * 1 |   1 2
 * 2 |     1 0
 * 3 |       1 2
 * 4 |         1 0
 * 5 |           1
 *
 *
 * Time Complexity: O(N^2)
 * Beats: 30.4 %
 */

class Solution {
 public:
  int countSubstrings(string s) {
    int n = s.size();
    std::vector<std::vector<int>> dp(n, vector<int>(n, 0));
    int count = 0;

    for (int g = 0; g < n; g++) {
      for (int i = 0, j = g; j < n; i++, j++) {
        if (g == 0) {
          dp[i][j] = 1;
          count++;
        } else if (g == 1) {
          if (s[i] == s[j]) {
            dp[i][j] = 2;
            count++;
          } else {
            dp[i][j] = 0;
          }
        } else {
          if (s[i] == s[j] && dp[i + 1][j - 1] != 0) {
            dp[i][j] = dp[i + 1][j - 1] + 2;
            count++;
          }
        }
      }
    }
    return count;
  }
};