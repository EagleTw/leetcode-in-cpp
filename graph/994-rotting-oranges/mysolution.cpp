// solution from:
// https://zxi.mytechroad.com/blog/searching/leetcode-994-rotting-oranges/
#include <queue>
#include <utility>
class Solution {
public:
  int orangesRotting(std::vector<std::vector<int>> &grid) {
    std::queue<std::pair<int, int>> q;
    int fresh = 0;
    int days = 0;

    // find all rotten orange
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 2) {
          q.emplace(i, j);
        } else if (grid[i][j] == 1) {
          fresh++;
        }
      }
    }

    // bfs
    std::vector<int> dirs = {1, 0, -1, 0, 1};
    while (!q.empty() && fresh) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        auto [y, x] = q.front();
        q.pop();
        for (int j = 0; j < 4; j++) {
          int dy = y + dirs[j];
          int dx = x + dirs[j + 1];
          if (dx < 0 || dx >= grid[0].size() || dy < 0 || dy >= grid.size() ||
              grid[dy][dx] != 1)
            continue;
          fresh--;
          grid[dy][dx] = 2;
          q.emplace(dy, dx);
        }
      }
      days++;
    }

    return fresh ? -1 : days;
  }
};