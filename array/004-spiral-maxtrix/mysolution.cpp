#include <vector>
class Solution {
public:
  std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    std::vector<int> ans;
    std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));

    std::vector<int> dir = {1, 0, -1, 0, 1};
    int x = 0, y = 0; // initialize starting point
    int count = 0;    // count changing directing in a streak
    int i = 0;        // direction, range: [0, 3]

    ans.push_back(matrix[0][0]);
    visited[0][0] = true;

    while (count < 4) {
      const int dy = y + dir[i + 1]; // peek next point
      const int dx = x + dir[i];
      if (dy >= 0 && dy < m && dx >= 0 && dx < n && !visited[dy][dx]) {
        ans.push_back(matrix[dy][dx]);
        visited[dy][dx] = true;
        count = 0;
        y = dy;
        x = dx;
      } else {
        count++;
        i = (i + 1) % 4; // change direction
      }
    }

    return ans;
  }
};