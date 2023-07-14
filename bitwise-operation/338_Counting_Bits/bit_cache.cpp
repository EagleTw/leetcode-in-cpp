class Solution {
 public:
  vector<int> countBits(int n) {
    std::vector<int> ret(n + 1);
    ret[0] = 0;

    for (int i = 1; i < n + 1; i++) {
      ret[i] = (i & 1) + ret[i >> 1];
    }
    return ret;
  }
};
