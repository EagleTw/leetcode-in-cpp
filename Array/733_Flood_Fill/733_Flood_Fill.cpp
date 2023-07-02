class Solution {
 public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                int new_color) {
    if (image[sr][sc] == new_color) return image;

    int m = image[0].size();
    int n = image.size();
    dfsFloodFill(image, sc, sr, image[sr][sc], new_color, m, n);

    return image;
  }

  void dfsFloodFill(vector<vector<int>>& image, int x, int y, int old_color,
                    int new_color, int m, int n) {
    if (x >= m || x < 0 || y >= n || y < 0) return;
    if (image[y][x] != old_color) return;

    image[y][x] = new_color;
    dfsFloodFill(image, x + 1, y, old_color, new_color, m, n);
    dfsFloodFill(image, x - 1, y, old_color, new_color, m, n);
    dfsFloodFill(image, x, y + 1, old_color, new_color, m, n);
    dfsFloodFill(image, x, y - 1, old_color, new_color, m, n);
  }
};
