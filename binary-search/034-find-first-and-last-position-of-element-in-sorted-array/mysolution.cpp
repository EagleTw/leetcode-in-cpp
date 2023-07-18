#include <vector>
class Solution {
public:
  std::vector<int> searchRange(std::vector<int> &nums, int target) {
    std::vector<int> ret(2, -1);
    int left = 0, right = nums.size() - 1;

    // find first position
    while (left <= right) { // 注意! [0, nums.size() - 1]
      int mid = left + (right - left) / 2;
      if (nums[mid] < target) {
        left = mid + 1;
      } else if (nums[mid] >= target) {
        right = mid - 1;
      }
    }
    const int first = right + 1; // 注意! right 為「小於 target 的最大數 index」
    if (first >= 0 && first < nums.size() && nums[first] == target)
      ret[0] = first;
    else
      return ret;

    // find last position
    right = nums.size() - 1; // left 不設為 0
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] <= target) {
        left = mid + 1;
      } else if (nums[mid] > target) {
        right = mid - 1;
      }
    }
    const int last = left - 1; // 注意! right 為「大於 target 的最小數 index」
    if (last >= 0 && last < nums.size() && nums[last] == target)
      ret[1] = last;

    return ret;
  }
};
