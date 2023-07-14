class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;

    std::map<char, int> charMap;

    for (int i = 0; i < s.size(); i++) {
      charMap[s[i]]++;
    }
    for (int i = 0; i < t.size(); i++) {
      charMap[t[i]]--;
      if (charMap[t[i]] < 0) return false;
    }
    return true;
  }
};
