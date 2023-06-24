class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    // brute force
    size_t vec_size = prices.size();
    int max_profit = INT_MIN;
    int l = 0, r = 0;

    for (; r < vec_size; r++) {
      if (prices[r] < prices[l]) {
        l = r;
      }
      max_profit = max(max_profit, prices[r] - prices[l]);
    }
    return max_profit;
  }
};
