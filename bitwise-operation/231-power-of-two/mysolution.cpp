// decimal | binary | popcount |  return
//       2 | 0x0010 |        1 |    true
//       3 | 0x0011 |        2 |    false
//       7 | 0x0111 |        3 |    false
//       8 | 0x0100 |        1 |    true

class Solution {
public:
  bool isPowerOfTwo(int n) {
    if (n < 0)
      return false;

    return (__builtin_popcount(n) == 1);
  }
};
