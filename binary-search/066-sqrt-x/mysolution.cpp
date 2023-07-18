class Solution {
public:
  int mySqrt(int x) {
    if (x == 0) // check added to handle div by zero
      return 0;

    int lo = 1;
    int hi = x;
    while (lo <= hi) { // 注意! while 停止條件是 lo = hi + 1
      int mid = lo + (hi - lo) / 2;
      if (mid == x / mid) { // int overflow: `mid * mid == x`
        return mid;
      } else if (mid > x / mid) { // [mid, hi] 不是我們要找的範圍
        hi = mid - 1;
      } else if (mid < x / mid) { // 找滿足這個條件，最右邊的位置
        lo = mid + 1;
      }
    }
    return hi;
  }
};
