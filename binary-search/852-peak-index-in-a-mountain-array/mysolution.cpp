#include <vector>
class Solution {
public:
  int peakIndexInMountainArray(std::vector<int> &arr) {
    int lo = 0, hi = arr.size() - 1;
    while (lo <= hi) {
      const int mid = lo + (hi - lo) / 2;
      if (arr[mid] > arr[mid + 1])
        hi = mid - 1;
      else
        lo = mid + 1;
    }
    return lo;
  }
};
