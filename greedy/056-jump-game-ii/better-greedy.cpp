class Solution {
public:
  int jump(vector<int> &nums) {
    assert(nums.size() >= 1 && nums.size() <= 1e4);
    int ans = -1;
    int l = 0, r = 0;
    while (l < nums.size()) {
      ans++;
      int furtherst = 0;
      for (int i = l; i <= r && i < nums.size(); i++) {
        furtherst = max(furtherst, i + nums[i]);
      }
      l = r + 1;
      r =  furtherst;
    }
    return ans;
  }
};
