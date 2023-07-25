#include <vector>
class Solution {
public:
  int removeDuplicates(std::vector<int> &nums) {
    int slow = 0;
    int fast = 0;
    while (fast < nums.size()) { // can be for-loop
      if (nums[fast] == nums[slow]) {
        fast++;
      } else if (fast != slow && nums[fast] != nums[slow]) {
        slow++;
        std::swap(nums[fast], nums[slow]);
        fast++;
      }
    }
    return slow + 1;
  }
};