// average time O(n^2)
// worst case time O(n^2)
class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    assert(k >= 0 && k <= nums.size());
    int lo = 0, hi = nums.size() - 1;
    while (true) {
      const int pos = partition(nums, lo, hi);
      if (pos == k - 1) {
        return nums[pos];
      } else if (pos < k - 1) {
        lo = pos + 1;
      } else {
        hi = pos - 1;
      }
    }
    return -1;
  }

private:
  int partition(vector<int> &nums, int lo, int hi) {
    // sort 左小右大
    int pivot = nums[lo], i = lo + 1, j = hi;
    while (i <= j) {
      if (nums[i] < pivot && nums[j] > pivot) {
        swap(nums[i], nums[j]);
        i++;
        j--;
      }
      if (nums[i] >= pivot)
        i++;
      if (nums[j] <= pivot)
        j--;
    }
    swap(nums[lo], nums[j]);
    return j;
  }
};
