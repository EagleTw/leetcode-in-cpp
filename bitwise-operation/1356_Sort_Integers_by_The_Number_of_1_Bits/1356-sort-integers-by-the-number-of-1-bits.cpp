class Solution {
public:
  vector<int> sortByBits(vector<int> &arr) {
    sort(arr.begin(), arr.end(), compare);
    return arr;
  }

  static bool compare(int a, int b) {
    int p = __builtin_popcount(a);
    int q = __builtin_popcount(b);

    if (p == q) {
      return a < b;
    }
    return (p < q);
  }
};
