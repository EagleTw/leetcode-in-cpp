// 如果每個字母只出現一次，可以這樣寫
class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    std::unordered_map<int32_t, vector<string>> map;

    for (auto str : strs) {
      int32_t ascii = 0;
      for (auto c : str) {
        ascii |= (1 << (c - 'a'));
      }
      if (map.find(ascii) != map.end())
        map[ascii].push_back(str);
      else
        map.insert({ascii, {str}});
    }

    std::vector<std::vector<string>> ret;
    for (auto it : map) {
      ret.push_back(it.second);
    }

    return ret;
  }
};

// 如果字母可以重複
class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    std::unordered_map<string, vector<string>> map;

    for (auto str : strs) {
      string t = str;
      std::sort(t.begin(), t.end());
      map[t].push_back(str);
    }

    std::vector<std::vector<string>> ret;
    for (auto it : map) {
      ret.push_back(it.second);
    }

    return ret;
  }
};
