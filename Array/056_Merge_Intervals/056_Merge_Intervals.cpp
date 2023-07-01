// TLE
// Comment said it is about "erase"
class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() == 0) return {};
    std::sort(intervals.begin(), intervals.end(), compare());

    auto slow = intervals.begin();
    auto fast = slow;

    while (slow != intervals.end() && (slow + 1) != intervals.end()) {
      fast = slow + 1;
      if ((*fast)[0] > (*slow)[1]) {
        slow++;
      } else {
        (*slow)[1] = std::max((*slow)[1], (*fast)[1]);
        intervals.erase(fast);
      }
    }
    return intervals;
  }

 private:
  struct compare {
    inline bool operator()(std::vector<int> x, std::vector<int> y) {
      return x[0] < y[0];
    }
  };
};
