char nextGreatestLetter(vector<char> &letters, char target) {
  return upper_bound(letters.begin(), letters.end(), target) != letters.end()
             ? *upper_bound(letters.begin(), letters.end(), target)
             : *letters.begin();
}
