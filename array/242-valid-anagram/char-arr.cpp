class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;

    int alphabet[26] = {0};

    for (int i = 0; i < s.size(); i++) {
      alphabet[s[i] - 'a']++;
    }

    for (int i = 0; i < t.size(); i++) {
      if (--alphabet[t[i] - 'a'] < 0) return false;
    }
    return true;
  }
};
