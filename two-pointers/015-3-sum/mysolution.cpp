#include <algorithm>
#include <vector>
class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::vector<std::vector<int>> ans;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() && nums[i] <= 0; i++) {
      if (i >= 1 && nums[i] == nums[i - 1])
        continue;

      int sum = 0 - nums[i];
      int left = i + 1;
      int right = nums.size() - 1;

      while (left < right) {
        if (nums[left] + nums[right] == sum) {
          ans.push_back({nums[i], nums[left], nums[right]});

          while (left < right && nums[left] == nums[left + 1])
            left++;
          while (left < right && nums[right] == nums[right - 1])
            right--;

          left++;
          right--;
        } else if (nums[left] + nums[right] > sum) {
          right--;
        } else {
          left++;
        }
      }
    }

    return ans;
  }
};

