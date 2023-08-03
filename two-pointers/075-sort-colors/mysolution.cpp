/*
Example: [2, 0, 1]

1.
[2, 0, 1]
 ^     ^
 l,cur r

2.
[1, 0, 2]
 ^  ^  ^ -> r
 l  cur

3.
[0, 1, 2]
    ^  ^
    l  r, cur
*/

#include <vector>
class Solution {
public:
  void sortColors(std::vector<int> &nums) {
    assert(nums.size() > 0 && nums.size() <= 300);

    int l = 0;
    int r = nums.size() - 1;
    int cur = 0;
    while (cur <= r) {
      switch (nums[cur]) {
      case 0:
        std::swap(nums[cur], nums[l]);
        l++;
        cur++; // did not add this line in first time
        break;
      case 1:
        cur++;
        break;
      case 2:
        std::swap(nums[cur], nums[r]);
        r--;
        break;
      }
    }
  }
};
