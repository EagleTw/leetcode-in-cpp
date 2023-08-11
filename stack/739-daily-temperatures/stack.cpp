// Need practice
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    // monotinic non-increasing stack
    stack<int> s;
    vector<int> ans(temperatures.size(), 0);
    for (int i = 0; i < temperatures.size(); i++) {
      while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
        ans[s.top()] = i - s.top();
        s.pop();
      }
      s.push(i);
    }
    return ans;
  }
};
