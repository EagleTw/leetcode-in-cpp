// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) { // 能力二分法
    int lo = 1, hi = n;
    while (lo <= hi) {
      const int mid = lo + ((hi - lo) >> 1);
      if (isBadVersion(mid)) {
        hi = mid - 1;
      } else if (!isBadVersion(mid)) {
        lo = mid + 1;
      }
    }
    return lo;
  }
};
