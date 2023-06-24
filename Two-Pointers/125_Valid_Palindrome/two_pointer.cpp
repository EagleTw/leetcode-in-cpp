class Solution {
 public:
  bool isPalindrome(string s) {
    int front = 0;
    int rear = s.size();

    while (front < rear) {
      while (!isalnum(s[front]) && front < rear) {
        front++;
      }
      while (!isalnum(s[rear]) && front < rear) {
        rear--;
      }
      if (toupper(s[front++]) != toupper(s[rear--])) return false;
    }
    return true;
  }
};
