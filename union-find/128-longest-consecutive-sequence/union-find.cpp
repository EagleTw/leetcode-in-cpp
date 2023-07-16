#include <unordered_map>
#include <vector>
class Solution {
public:
  int longestConsecutive(std::vector<int> &nums) {
    // union find
    std::unordered_map<int, int> hash; // key: nums
                                       // value: count adj consecutive number
    int ans = 0;

    for (const auto &num : nums) {
      if (hash.count(num)) // found duplicate
        continue;

      auto it_l = hash.find(num - 1);
      auto it_r = hash.find(num + 1);

      int l = (it_l != hash.end()? it_l->second : 0);
      int r = (it_r != hash.end()? it_r->second : 0);
      int tmp = l + r + 1;

      hash[num] = hash[num - l] = hash[num + r] = tmp;
      ans = std::max(ans, tmp);
    }
    return ans;
  }
};
