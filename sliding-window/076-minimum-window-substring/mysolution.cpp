#include <algorithm>
#include <climits>
#include <cstdio>
#include <string>
#include <unordered_map>
#include <utility>
class Solution {
public:
  std::string minWindow(std::string s, std::string t) {
    const int m = s.size();
    const int n = t.size();
    if (m < n)
      return "";

    std::unordered_map<char, int> window, map;
    int window_count = 0, map_count = 0;
    for (const char &c : t) {
      map[c]++;
    }

    // sliding window (front: i, back: j)
    std::pair<int, int> min_sub = {-1, m};
    int i = 0, j = 0;
    for (j = 0; j < m; j++) {
      printf("(%d, %d) --> (%d, %d)\n", i, j, min_sub.first, min_sub.second);
      while(i <= j && isSubstring(window, map)) {
        if (j - i < min_sub.second - min_sub.first)
          min_sub = {i, j};
        window[s[i]]--;
        i++;
      }
    }

    if (min_sub.second - min_sub.first + 1 > m)
      return "";

    return s.substr(min_sub.first, min_sub.second - min_sub.first + 1);
  }

private:
  bool isSubstring(std::unordered_map<char, int> &window,
                   std::unordered_map<char, int> &map) {
    for (const auto &m : map) {
      const char c = m.first;
      const char val = m.second;
      if (window[c] < val) {
        return false;
      }
    }
    return true;
  }
};
