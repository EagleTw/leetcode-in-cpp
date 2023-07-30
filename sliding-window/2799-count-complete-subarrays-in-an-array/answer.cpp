// Need practice!
class Solution {
public:
  int countCompleteSubarrays(vector<int> &nums) {
    assert(nums.size());

    int ans = 0;
    unordered_map<int, int> mp, all;
    for (const auto &num : nums) {
      assert(num >= 1 && num <= 2000);
      all[num]++;
    }

    // sliding window
    int l = 0, r = 0;
    for (; r < nums.size(); r++) {
      mp[nums[r]]++;
      while (l <= r && mp.size() == all.size()) {
        ans += (nums.size() - r);
        /* Example: [1,2,2,3,3,4]
         * 如果 [1,2,2,3] 符合題意，那麼 [1,2,2,3,3] 和 [1,2,2,3,3,4] 也都是合法
         * 所個數為 nums.size() - r
         */
        mp[nums[l]]--;
        if (!mp[nums[l]])
          mp.erase(nums[l]); // 移除 element，而不是把 value 設為 0
        l++;
      }
    }
    return ans;
  }
};
