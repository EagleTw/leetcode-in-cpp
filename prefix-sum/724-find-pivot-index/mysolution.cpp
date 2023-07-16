class Solution {
public:
  int pivotIndex(vector<int> &nums) {
    int prefix = 0;
    int suffix = 0;
    vector<int> v(nums.size(), 0);

    for (int i = 0; i < nums.size(); i++) {
      v[i] = prefix;
      prefix += nums[i];
    }

    for (int i = nums.size() - 1; i >= 0; i--) {
      v[i] -= suffix;
      suffix += nums[i];
    }

    for (int i = 0; i < nums.size(); i++) {
      if (v[i] == 0)
        return i;
    }
    return -1;
  }
};
