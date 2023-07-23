class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    vector<int> count(nums.size() + 1, 0);

    for (const auto &num : nums) {
      if (++count[num] > 1)
        return num;
    }
    return -1;
  }
};
