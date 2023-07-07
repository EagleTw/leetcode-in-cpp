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

class Solution class Solution {
public:
  int numDecodings(string s) {
    if (s[0] == '0')
      return 0;
    return dfs(s, s.size() - 1);
  }

private:
  int dfs(string s, int right) {
    if (right == 0 && s[right] != '0')
      return 1;
    else if (right == -1)
      return 1;
    else if (right < -1)
      return 0;

    int ret = 0;

    // [0:right-1] a
    const int val1 = s[right] - '0';
    if (val1 >= 1)
      ret += dfs(s, right - 1);

    // [0:right-2] ab
    if (right >= 1 && s[right - 1] != '0') {
      const int val2 = (s[right - 1] - '0') * 10 + s[right] - '0';
      if (val2 <= 26 && val2 > 0)
        ret += dfs(s, right - 2);
    }
    return ret;
  }
};
