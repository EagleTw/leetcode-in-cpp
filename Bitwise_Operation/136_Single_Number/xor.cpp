class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int sum = 0;
    for (auto i : nums) sum ^= i;
    return sum;
  }
};
