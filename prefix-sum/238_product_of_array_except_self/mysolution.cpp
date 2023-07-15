#include <vector>
class Solution {
public:
  std::vector<int> productExceptSelf(std::vector<int> &nums) {

    std::vector<int> ans(nums.size(), 1);

    // pass 1: find prefix sum
    int prefix = 1;
    for (int i  = 0; i < nums.size(); i++) {
      ans[i] = prefix;
      prefix *= nums[i];
    }

    // pass 2: find suffix sum
    int suffix = 1;
    for (int i  = nums.size() - 1; i >= 0; i--) {
      ans[i] *= suffix;
      suffix *= nums[i];
    }

    return ans;
  }
};
