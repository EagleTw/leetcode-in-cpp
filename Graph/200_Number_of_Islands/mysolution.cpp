// faster than 93.6 %
class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    int count = 0;

    for (int y = 0; y < grid.size(); y++) {
      for (int x = 0; x < grid[0].size(); x++) {
        if (grid[y][x] == '1') {
          markFound(grid, x, y);
          count++;
        }
      }
    }

    return count;
  }

private:
  void markFound(vector<vector<char>> &grid, int x, int y) {
    if (x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size())
      return;
    else if (grid[y][x] == '0')
      return;

    grid[y][x] = '0';

    markFound(grid, x + 1, y);
    markFound(grid, x - 1, y);
    markFound(grid, x, y + 1);
    markFound(grid, x, y - 1);  // not needed

    return;
  }
};
