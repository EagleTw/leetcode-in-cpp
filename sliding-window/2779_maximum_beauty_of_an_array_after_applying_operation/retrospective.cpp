#include <vector>
class Solution {
public:
  int maximumBeauty(std::vector<int> &nums, int k) {
    std::sort(nums.begin(), nums.end());
    int ans = 0;
    int l = 0, r = 0; // left/right index

    while (r < nums.size()) {
      if (nums[r] - nums[l] <= 2 * k) { // mistake made here: '<'
        ans = std::max(ans, r - l + 1);
        r++;
      } else {
        l++;
      }
    }

    return ans;
  }
};
