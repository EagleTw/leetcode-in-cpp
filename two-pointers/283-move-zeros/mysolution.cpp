// Need practice!
class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    assert(nums.size());
    int prev = 0, cur = 0;
    while (cur < nums.size()) {
      if (nums[cur] != 0) {
        swap(nums[prev], nums[cur]);
        prev++;
      }
      cur++;
    }
    return;
  }
};
