class Solution {
 public:
  bool isPalindrome(int x) {
    string s = std::to_string(x);
    int left = 0;
    int right = s.size() - 1;
    while (left < right) {
      if (s[left] != s[right]) return false;
      left++;
      right--;
    }
    return true;
  }
};
