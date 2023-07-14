// Time Limit Exceeded
#include <vector>
class Solution {
public:
  std::vector<std::vector<int>> insert(std::vector<std::vector<int>> &intervals,
                                       std::vector<int> &newInterval) {
    auto it = intervals.begin();
    while (it != intervals.end() && (*it)[0] < newInterval[0])
      it++;
    intervals.insert(it, newInterval);

    // create a extra array
    // the speed will be faster than in-place (erase is costy).
    std::vector<std::vector<int>> ans;
    for (const auto &it : intervals) {
      if (ans.empty() || ans.back()[1] < it[0])
        ans.push_back(it);
      else
        ans.back()[1] = std::max(it[1], ans.back()[1]);
    }

    return ans;
  }

private:
  static bool compare(std::vector<int> a, std::vector<int> b) {
    return a[0] < b[0];
  }
};