class Solution {
 private:
  void backtrack(vector<int>& nums, int target,
                 std::vector<std::vector<int>>& ret, std::vector<int>& curSet,
                 int index) {
    if (target == 0) {
      ret.push_back(curSet);
      return;
    }

    for (int i = index; i < nums.size(); i++) {
      if (i != index && nums[i] == nums[i - 1]) continue;
      if (nums[i] > target) break;
      curSet.push_back(nums[i]);
      backtrack(nums, target - nums[i], ret, curSet, i + 1);
      curSet.pop_back();
    }
  }

 public:
  vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
    std::vector<std::vector<int>> ret;
    std::vector<int> curSet;
    std::sort(nums.begin(), nums.end());
    backtrack(nums, target, ret, curSet, 0);
    return ret;
  }
};
