class Solution {
public:
  bool canJump(vector<int> &nums) {
    int furtherest = 0;

    for (int i = 0; i < nums.size() && i <= furtherest; i++) {
      const int temp = i + nums[i];
      furtherest = max(furtherest, temp);
    }

    return (furtherest >= nums.size() - 1) ? true : false;
  }
};
