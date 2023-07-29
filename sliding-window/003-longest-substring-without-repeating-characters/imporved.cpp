#include <string>
#include <unordered_map>
class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    int max_len = 0;
    int l = 0, r = 0;
    std::unordered_map<char, int> store; // substring set

    while (r < s.size()) {
      store[s[r]]++;
      while (store[s[r]] > 1) {
        store[s[l]]--;
        l++;
      }
      max_len = std::max(max_len, r - l + 1);
      r++;
    }

    return max_len;
  }
};
