class Solution {
public:
  int trap(vector<int> &height) {
    assert(height.size());
    int ans = 0;
    // two pointer technique
    int l = 0, r = height.size() - 1;
    int max_left = 0, max_right = 0;

    while (l <= r) {
      if (height[l] <= height[r]) {
        max_left = max(max_left, height[l]);
        int temp = max_left - height[l];
        if (temp > 0)
          ans += temp;
        l++;
      } else {
        max_right = max(max_right, height[r]);
        int temp = max_right - height[r];
        if (temp > 0)
          ans += temp;
        r--;
      }
    }
    return ans;
  }
};
