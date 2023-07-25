class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int prev = 0;
    for (int cur = 0; cur < nums.size(); cur++) {
      if (nums[cur] != val) {
        std::swap(nums[cur], nums[prev]);
        prev++;
      }
    }
    return prev;
  }
};
