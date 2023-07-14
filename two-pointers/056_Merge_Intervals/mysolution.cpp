#include <algorithm>
#include <vector>
class Solution {
public:
  std::vector<std::vector<int>>
  merge(std::vector<std::vector<int>> &intervals) {
    std::sort(intervals.begin(), intervals.end(), compare);

    std::vector<std::vector<int>> ans;

    for (const auto &it : intervals) {
      if (ans.empty() || ans.back()[1] < it[0]) {
        ans.push_back(it);
      } else {
        ans.back()[1] = std::max(ans.back()[1], it[1]);
      }
    }
    return ans;
  }

private:
  static bool compare(const std::vector<int> &a, const std::vector<int> &b) {
    return a[0] < b[0];
  }
};