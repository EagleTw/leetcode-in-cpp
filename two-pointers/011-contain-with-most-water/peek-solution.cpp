class Solution {
public:
  int maxArea(vector<int> &height) {
    // constraints
    assert(height.size() >= 2 && height.size() <= 1e5);
    for (const int &h : height) {
      assert(h >= 0 && h <= 1e5);
    }
    // two pointer
    int l = 0, r = height.size() - 1;
    int ans = min(height[l], height[r]) * (r - l);

    while (l < r) {
      int h = min(height[l], height[r]);
      ans = max(ans, h * (r - l));
      if (height[l] > height[r])
        r--;
      else
        l++;
    }
    return ans;
  }
};
