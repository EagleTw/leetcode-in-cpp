/*
 * "abcccba"
 * Time Complexity: O(N^2)
 * beats 5.1 %
 */

class Solution {
 public:
  string longestPalindrome(string s) {
    int max_len = INT_MIN;
    int right = INT_MIN;
    int left = INT_MIN;

    for (int i = 0; i < s.size(); i++) {
      int tmp = longestDistance(s, i, i);
      if (tmp > max_len) {
        max_len = tmp;
        right = i;
        left = i;
      }
      tmp = longestDistance(s, i, i + 1);
      if (tmp > max_len) {
        max_len = tmp;
        right = i;
        left = i + 1;
      }
    }
    return s.substr(left - max_len / 2, max_len);
  }

 private:
  int longestDistance(string s, int lIndex, int rIndex) {
    int ssize = s.size() - 1;

    if (lIndex < 0 || lIndex > ssize || rIndex < 0 || rIndex > ssize)
      return rIndex - lIndex - 1;

    if (s[lIndex] != s[rIndex]) return rIndex - lIndex - 1;

    return longestDistance(s, lIndex - 1, rIndex + 1);
  }
};
