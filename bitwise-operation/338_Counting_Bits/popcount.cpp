class Solution {
 public:
  vector<int> countBits(int n) {
    std::vector<int> ret;
    for (int i = 0; i < n + 1; i++) {
      ret.push_back(__builtin_popcount(i));
    }
    return ret;
  }
};
