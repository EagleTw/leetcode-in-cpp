// Need practice!
class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    assert(nums.size());
    int last = 0, cur = 0;
    while (cur < nums.size()) {
      if (nums[cur] != 0) {
        swap(nums[last], nums[cur]);
        last++;
      }
      cur++;
    }
    return;
  }
};
