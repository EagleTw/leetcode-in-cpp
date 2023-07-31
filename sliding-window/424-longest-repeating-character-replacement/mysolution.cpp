class Solution {
public:
  int characterReplacement(string s, int k) {
    const int n = s.size();
    std::unordered_map<char, int> mp;
    int ans = -1;
    int i = 0;    // <- window start
    int j = 0;    // <- window end
    int maxC = 0; // <- max no. of repeating elem

    while (j < n) {
      mp[s[j]]++;
      maxC = std::max(maxC, mp[s[j]]);
      int cur_len = j - i + 1;
      if (cur_len - maxC > k) {
        mp[s[i]]--;
        i++;
        cur_len--;
      }
      ans = std::max(ans, cur_len);
      j++;
    }

    return ans;
  }
};
