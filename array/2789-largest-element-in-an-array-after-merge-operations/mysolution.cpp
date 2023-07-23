class Solution {
public:
  long long maxArrayValue(vector<int> &nums) {
    // always check range
    assert(nums.size() >= 0 && nums.size() < 1e5);
    for (const int &x : nums) {
      assert(x >= 1 && x <= 1e5);
    }

    vector<long long> ll(nums.size());
    for (int i = 0; i < nums.size(); i++)
      ll[i] = nums[i];

    // greedy from backward
    for (int i = ll.size() - 2; i >= 0; i--) {
      if (ll[i] <= ll[i + 1]) {
        ll[i] += ll[i + 1];
      }
    }

    return *max_element(ll.begin(), ll.end());
  }
};
