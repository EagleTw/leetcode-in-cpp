/*
 * [ 4 1 2 4 5 ]
 * Max Profit -> Buy low, sell high
 *
 * [ 4 1 2 4 5 ]
 *   ^ ^
 *   i j   profit = 1 - 3 = -2 --- less than 0
 *                             --- update smallest point i
 *
 * [ 4 1 2 4 5 ]
 *     ^     ^
 *     i     j    profit = 5 - 1 = 4
 */

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
