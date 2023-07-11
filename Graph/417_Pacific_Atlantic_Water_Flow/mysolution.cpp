// beats 54.3 %
class Solution {
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    int m = heights[0].size();
    int n = heights.size();

    vector<vector<bool>> pacific(n, vector<bool>(m, 0));
    vector<vector<bool>> atlantic(n, vector<bool>(m, 0));

    for (int c = 0; c < m; c++) {
      flowBackward(heights, pacific, 0, c, 0);
      flowBackward(heights, atlantic, n - 1, c, 0);
    }
    for (int r = 0; r < n; r++) {
      flowBackward(heights, pacific, r, 0, 0);
      flowBackward(heights, atlantic, r, m - 1, 0);
    }

    vector<vector<int>> ret;
    for (int c = 0; c < m; c++) {
      for (int r = 0; r < n; r++) {
        if (pacific[r][c] && atlantic[r][c])
          ret.push_back({r, c});
      }
    }

    return ret;
  }

private:
  void flowBackward(vector<vector<int>> &heights, vector<vector<bool>> &visited,
                    int r, int c, int prevHeight) {
    if (c < 0 || c >= heights[0].size() || r < 0 || r >= heights.size())
      return;

    if (visited[r][c])
      return;

    if (heights[r][c] < prevHeight)
      return;

    visited[r][c] = 1;

    flowBackward(heights, visited, r, c + 1, heights[r][c]);
    flowBackward(heights, visited, r, c - 1, heights[r][c]);
    flowBackward(heights, visited, r + 1, c, heights[r][c]);
    flowBackward(heights, visited, r - 1, c, heights[r][c]);

    return;
  }
};
