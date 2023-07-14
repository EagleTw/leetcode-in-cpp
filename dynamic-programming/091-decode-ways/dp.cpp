// TLE

/*
 * Example 1: "12"
 * "1 2", "12"  --> 2 ways
 *
 * Example 2: "1021"
 * "10 2 1", "10 21" --> 2 ways
 *
 */

// 1021
//              root
//           1  /   \ 21
//            102    10
//         2  / \  10/ \0
//           10 x  nil  x
//          / \
//        nil x
//
//        valid solution -- 2

class Solution {
public:
  int numDecodings(string s) {
    if (s[0] == '0')
      return 0;

    std::vector<int> dp(s.size() + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= s.size(); i++) {
      // [0..i-1] i
      if (s[i - 1] != '0') {
        const int val1 = stoi(s.substr(i - 1, 1));
        if (val1 > 0 && val1 < 10)
          dp[i] += dp[i - 1];
      }

      // [0..i-2] i2
      if (s[i - 2] != '0') {
        const int val2 = stoi(s.substr(i - 2, 2));
        if (val2 > 0 && val2 < 27)
          dp[i] += dp[i - 2];
      }
    }
    return dp[s.size()];
  }
};
