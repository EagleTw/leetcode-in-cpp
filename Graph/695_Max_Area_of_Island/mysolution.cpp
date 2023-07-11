class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    if (!grid.size())
      return 0;

    int maxArea = 0;

    for (int y = 0; y < grid.size(); y++) {
      for (int x = 0; x < grid[0].size(); x++) {
        maxArea = std::max(maxArea, dfs(grid, x, y));
      }
    }
    return maxArea;
  }

private:
  int dfs(vector<vector<int>> &grid, int x, int y) {
    if (x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size())
      return 0;
    if (grid[y][x] == 0)
      return 0;

    int ret = 1;
    grid[y][x] = 0;

    ret += dfs(grid, x + 1, y);
    ret += dfs(grid, x - 1, y);
    ret += dfs(grid, x, y + 1);
    ret += dfs(grid, x, y - 1);

    return ret;
  }
};
