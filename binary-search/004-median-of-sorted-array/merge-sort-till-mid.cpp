// Time Complexity: O(n/2)
class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    const int m = nums1.size();
    const int n = nums2.size();
    const int total = m + n;
    const int stop = (total + 1) / 2;

    vector<int> sorted;
    int i = 0, j = 0;
    while (i < m && j < n && i + j <= stop) {
      if (nums1[i] < nums2[j]) {
        sorted.emplace_back(nums1[i]);
        i++;
      } else {
        sorted.emplace_back(nums2[j]);
        j++;
      }
    }
    while (i < m && i + j <= stop) {
      sorted.emplace_back(nums1[i]);
      i++;
    }
    while (j < n && i + j <= stop) {
      sorted.emplace_back(nums2[j]);
      j++;
    }

    double ans = 0.0;
    if (total & 1) {
      // odd
      ans = sorted[(total + 1) / 2 - 1]; // remember `index = elem - 1`
    } else {
      ans = (sorted[(total + 1) / 2 - 1] + sorted[(total + 1) / 2]) * 0.5;
    }

    return ans;
  }
};