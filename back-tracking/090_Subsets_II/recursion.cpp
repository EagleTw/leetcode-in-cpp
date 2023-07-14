private:
void subsets(std::vector<int> nums, int i, vector<int>& sub,
             vector<vector<int>>& subs) {
  subs.push_back(sub);

  for (int j = i; j < nums.size(); j++) {
    if (j > i && nums[j] == nums[j - 1]) continue;
    sub.push_back(nums[j]);
    subsets(nums, j + 1, sub, subs);
    sub.pop_back();
  }
}

public:
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
  vector<vector<int>> subs;
  vector<int> sub;
  std::sort(nums.begin(), nums.end());
  subsets(nums, 0, sub, subs);
  return subs;
}
}
;
