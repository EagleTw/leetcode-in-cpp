class Solution {
public:
  int matrixScore(vector<vector<int>> &grid) {
    int m = grid[0].size();
    int n = grid.size();

    for (int j = 0; j < n; j++) {
      if (!grid[j][0]) {
        for (int i = 0; i < m; i++) {
          grid[j][i] ^= 1;
        }
      }
    }

    for (int i = 1; i < m; i++) {
      int count1 = 0;
      for (int j = 0; j < n; j++) {
        if (grid[j][i] == 1) {
          count1++;
        }
      }
      if (count1 < n - count1) {
        for (int j = 0; j < n; j++) {
          grid[j][i] ^= 1;
        }
      }
    }

    int ret = 0;
    for (int j = 0; j < n; j++) {
      for (int i = 0; i < m; i++) {
        ret += (1 << (m - 1 - i)) * grid[j][i];
      }
    }

    return ret;
  }
};
