class Solution {
 public:
  bool isPalindrome(int x) {
    // Handle negative numbers
    if (x < 0) {
      return false;
    }

    int original_num = x;
    long reversed_num = 0;

    // Reverse the number
    while (x > 0) {
      reversed_num = reversed_num * 10 + (x % 10);
      x /= 10;
    }

    // Check if the reversed number is equal to the original number
    return (original_num == reversed_num);
  }
};
