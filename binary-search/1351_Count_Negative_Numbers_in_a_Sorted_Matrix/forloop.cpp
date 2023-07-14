/*
 * TC: O(m*n)
 * SC: O(1)
 */

class Solution {
 public:
  int countNegatives(vector<vector<int>>& grid) {
    int count_negative = 0;
    int max_x = grid[0].size();
    int max_y = grid.size();

    for (int j = 0; j < max_y; j++) {
      for (int i = 0; i < max_x; i++) {
        printf("(x, y) = (%d, %d)\n", i, j);
        if (grid[j][i] < 0) {
          count_negative += (max_y - j) * (max_x - i);
          max_x = i;
        }
      }
      printf("max: (%d, %d)\n", max_x, max_y);
    }
    return count_negative;
  }
};
