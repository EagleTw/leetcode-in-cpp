class Solution {
public:
  int trap(vector<int> &height) {
    assert(height.size());

    vector<int> max_left(height.size(), 0);
    vector<int> max_right(height.size(), 0);

    max_left[0] = height.front();
    for (int i = 1; i < height.size(); i++) {
      max_left[i] = max(max_left[i - 1], height[i]);
    }

    max_right[height.size() - 1] = height.back();
    for (int i = height.size() - 2; i >= 0; i--) {
      max_right[i] = max(max_right[i + 1], height[i]);
    }

    int ans = 0;
    for (int i = 0; i < height.size(); i++) {
      const int temp = min(max_left[i], max_right[i]) - height[i];
      if (temp > 0)
        ans += temp;
    }

    return ans;
  }
};
