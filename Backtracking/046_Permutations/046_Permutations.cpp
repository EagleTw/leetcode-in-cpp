// Back-tracking sulution

class Solution {
 private:
  void helper(vector<int> nums, vector<vector<int>>& ret, vector<int>& curPermu,
              int depth) {
    if (depth == nums.size()) {
      ret.push_back(curPermu);
      return;
    }

    for (int i = depth; i < curPermu.size(); i++) {
      std::swap(curPermu[depth], curPermu[i]);
      helper(nums, ret, curPermu, depth + 1);
      std::swap(curPermu[depth], curPermu[i]);
    }
  }

 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ret;
    vector<int> curPermu = nums;
    helper(nums, ret, curPermu, 0);
    return ret;
  }
};
