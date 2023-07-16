// Weekly Contest 354 : TLE
// Time Complexity O(n^2)
#include <vector>
class Solution {
public:
  int maximumBeauty(std::vector<int> &nums, int k) {
    std::sort(nums.begin(), nums.end());
    std::vector<int> diff;
    for (int i = 1; i < nums.size(); i++) {
      diff.emplace_back(nums[i] - nums[i - 1]);
    }

    int sum = 0;
    int count = 1;
    int ans = 0;

    for (int i = 0; i < diff.size(); i++) {
      for (int j = i; j < diff.size(); j++) {
        if (sum + diff[j] <= 2 * k) {
          sum += diff[j];
          count++;
        } else if (sum + diff[j] > k) {
          break;
        }
      }
      ans = std::max(ans, count);
      sum = 0;
      count = 1;
    }

    return ans;
  }
};
