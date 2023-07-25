// Need practice!
#include <vector>
class Solution {
public:
  int removeDuplicates(std::vector<int> &nums) {
    assert(nums.size());
    if (nums.size() == 1) {
      return 1;
    } else if (nums.size() == 2) {
      return 2;
    }

    int i = 1;
    for (int j = 0; j < nums.size(); j++) {
      if (j == 0 || j == 1) {
        continue;
      } else if (nums[j] == nums[i] && nums[j] == nums[i - 1]) {
        continue;
      } else {
        i++;
        nums[i] = nums[j];
      }
    }
    return i + 1;
  }
};
