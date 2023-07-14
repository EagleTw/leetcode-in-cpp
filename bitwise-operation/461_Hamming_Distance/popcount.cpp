class Solution {
public:
  int hammingDistance(int x, int y) {
    int tmp = x ^ y;
    return __builtin_popcount(tmp);
  }
};
