class Solution {
public:
  vector<string> splitWordsBySeparator(vector<string> &words, char separator) {
    vector<string> ret;

    for (const auto &word : words) {
      if (!word.size())
        continue;

      int f = 0, r = 0; // front & rear
      for (; f < word.size() && f < word.size(); f++) {
        if (word[f] == separator) {
          if (f == r) {
            r++;
          } else {
            ret.push_back(string(word, r, f - r));
            r = f + 1;
          }
        }
      }
      if (f != r)
        ret.push_back(word, r, f - r); // using default C++ string construtor
    }

    return ret;
  }
};
