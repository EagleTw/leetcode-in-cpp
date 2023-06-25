class Solution {
 private:
  void subsets(std::vector<int> nums, int i, vector<int>& sub,
               vector<vector<int>>& subs) {
    if (i == nums.size()) {
      subs.push_back(sub);
      return;
    }

    // contains the next item
    sub.push_back(nums[i]);
    subsets(nums, i + 1, sub, subs);

    // does not contain the next item
    sub.pop_back();
    while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
    subsets(nums, i + 1, sub, subs);
  }

 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> subs;
    vector<int> sub;
    std::sort(nums.begin(), nums.end());
    subsets(nums, 0, sub, subs);
    return subs;
  }
};
