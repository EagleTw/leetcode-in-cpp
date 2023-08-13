class Solution {
public:
  int trap(vector<int> &height) {
    assert(height.size());
    int ans = 0;

    stack<int> ms; // decreasing monotonic stack (store index)
    for (int i = 0; i < height.size(); i++) {
      while (!ms.empty() && height[ms.top()] <= height[i]) {
        const int j = ms.top();
        ms.pop();
        if (ms.empty())
          break;

        const int bounded_height = min(height[i], height[ms.top()]) - height[j];
        const int bounded_width = i - ms.top() - 1;
        ans += bounded_height * bounded_width;
      }
      ms.push(i);
    }
    return ans;
  }
};
