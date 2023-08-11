#include <unordered_map>
#include <vector>
class Solution {
public:
  int longestConsecutive(std::vector<int> &nums) {
    if (nums.size() == 0)
      return 0;

    // basic map count
    set<int> set;

    for (const auto &num : nums) {
      if (!set.count(num))
        set.insert(num);
    }

    int prev = *set.begin();
    int ans = 1;
    int count = 1;

    for (const auto &elem : set) {
      if (elem == prev + 1) {
        count++;
        ans = max(ans, count);
      } else {
        count = 1;
      }
      prev = elem;
    }

    return ans;
  }
};
