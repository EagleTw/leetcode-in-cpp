// Example 1:
//
// nums = [2, 3, -2, 4]
//         ^
//         2
//            6
//               -12
//                  -48

class Solution {
public:
  int maxProduct(vector<int> &nums) {

    vector<int> imin(nums.size(), 0);
    vector<int> imax(nums.size(), 0);

    imin[0] = nums[0];
    imax[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == 0) {
        imax[i] = 0;
        imax[i] = 0;
      } else {
        int tmp_min = nums[i] * imin[i - 1];
        int tmp_max = nums[i] * imax[i - 1];
        if (tmp_min > tmp_max)
          std::swap(tmp_min, tmp_max);
        imin[i] = std::min(tmp_min, nums[i]);
        imax[i] = std::max(tmp_max, nums[i]);
      }
    }

    int global_max = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
      global_max = std::max(global_max, imax[i]);
    }
    return global_max;
  }
};
