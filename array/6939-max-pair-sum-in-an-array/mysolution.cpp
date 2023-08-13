// Time Complexity: O(nlogn)
// sort: log(n/10)
class Solution {
public:
  int maxSum(vector<int> &nums) {
    vector<vector<int>> hash(10, vector<int>());

    for (int i = 0; i < nums.size(); i++) {
      int temp = maxDigit(nums[i]);
      hash[temp].emplace_back(nums[i]);
    }

    // bucket hash
    int ans = 0;
    int bSizeOver2 = false;
    for (int i = 0; i < 10; i++) {
      if (hash[i].size() >= 2) {
        bSizeOver2 = true;
        sort(hash[i].begin(), hash[i].end(), std::greater<int>());
        ans = max(ans, hash[i][0] + hash[i][1]);
      }
    }

    if (!bSizeOver2)
      return -1;

    return ans;
  }

private:
  int maxDigit(int i) {
    int imax = 0;
    while (i) {
      int temp = i % 10;
      imax = max(temp, imax);
      i /= 10;
    }
    assert(imax >= 0 && imax <= 9);
    return imax;
  }
};