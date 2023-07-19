#include <algorithm>
#include <vector>
class Solution {
 public:
  int minEatingSpeed(std::vector<int>& piles, int h) {
    int low = 0;  // lower bound of k
    int high = *std::max_element(piles.begin(), piles.end());

    // find the smallest possible
    while (low <= high) {
      int mid = (low + high) / 2;
      if (canEat(piles, h, mid)) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return low;
  }
private:
  bool canEat(std::vector<int> &piles, int h, int div) {
    if (!div)
      return false;

    double sum = 0;
    for (const int &i : piles) {
      sum += (i % div) ? (i / div) + 1 : (i / div);
    }
    return sum <= h;
  }
};
