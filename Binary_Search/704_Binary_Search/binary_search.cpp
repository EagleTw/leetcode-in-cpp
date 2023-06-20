
class Solution {
  binarySearch(vector<int> v, int target) {
    int l = 0;
    int r = v.size()-1;
    int ret = -1;

    while (l <= r && l >= 0 && r < v.size()) {
      int mid = (l + r) / 2;
      if (v[mid] == target) {
        ret = mid;
        break;
      } else if (v[mid] < target) {
        r = mid--;
      } else {
        l = mid++;
      }
    }

    return ret;
  }
};
