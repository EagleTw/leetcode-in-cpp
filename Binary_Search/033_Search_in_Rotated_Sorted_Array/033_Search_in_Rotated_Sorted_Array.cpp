class Solution {
 public:
  int search(vector<int>& nums, int target) {
    if (target > nums[nums.size() - 1] && target < nums[0]) return -1;

    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
      const int mid = left + (right - left) / 2;
      const bool right_sorted = (nums[mid] <= nums[right]);
      if (target == nums[mid]) {
        return mid;
      }
      if (right_sorted) {
        if (target > nums[mid] && target <= nums[right]) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      } else { /* left sorted */
        if (target < nums[mid] && target >= nums[left]) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      }
    }
    return -1;
  }
};
