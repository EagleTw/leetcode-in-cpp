class Solution {
 public:
  int getSum(int a, int b) {
    int carry;
    while (b) {
      carry = a & b;
      a = a ^ b;
      b = ((unsigned int)carry) << 1;
      // beware of left shifting signed number
    }
    return a;
  }
};
