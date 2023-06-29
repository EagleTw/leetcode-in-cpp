class Solution {
 public:
  char nextGreatestLetter(vector<char>& letters, char target) {
    int left = 0;
    int right = letters.size() - 1;

    if (letters[left] > target || letters[right] <= target) return letters[0];

    while (left < right) {
      const int mid = left + (right - left) / 2;
      if (letters[mid] <= target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return letters[left];
  }
};
