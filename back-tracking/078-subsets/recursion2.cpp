class Solution {
 private:
  void subsets(std::vector<int> nums, int i, vector<int>& sub,
               vector<vector<int>>& subs) {
    if (i == nums.size()) {
      subs.push_back(sub);
      return;
    }

    sub.push_back(nums[i]);
    subsets(nums, i + 1, sub, subs);
    sub.pop_back();
    subsets(nums, i + 1, sub, subs);
  }

 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> subs;
    vector<int> sub;
    subsets(nums, 0, sub, subs);
    return subs;
  }
};
