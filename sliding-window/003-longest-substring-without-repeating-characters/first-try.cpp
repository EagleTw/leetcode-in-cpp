class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int max_len = 0;
    int l = 0, r = 0;
    std::unordered_set<char> ss; // substring set

    while (r < s.size()) {
      if (ss.find(s[r]) != ss.end()) {
        ss.erase(s[l]);
        l++;
      } else {
        ss.insert(s[r]);
        max_len = std::max(max_len, r - l + 1);
        r++;
      }
    }

    return max_len;
  }
};
