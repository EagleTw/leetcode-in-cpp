// beats: 29.64 %

class Solution {
 public:
  int islandPerimeter(vector<vector<int>>& grid) {
    for (int x = 0; x < grid[0].size(); x++) {
      for (int y = 0; y < grid.size(); y++) {
        if (grid[y][x]) {  // found land
          return dfs(grid, x, y);
        }
      }
    }
    return 0;
  }

 private:
  int dfs(vector<vector<int>>& grid, int x, int y) {
    if (x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size()) return 1;
    if (grid[y][x] == 0) return 1;
    if (grid[y][x] == -1) return 0;  // traversed

    int sum = 0;

    grid[y][x] = -1;
    sum += dfs(grid, x + 1, y);
    sum += dfs(grid, x - 1, y);
    sum += dfs(grid, x, y + 1);
    sum += dfs(grid, x, y - 1);

    return sum;
  }
};
