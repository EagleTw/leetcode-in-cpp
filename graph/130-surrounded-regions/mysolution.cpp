class Solution {
public:
  void solve(vector<vector<char>> &board) {
    vector<vector<bool>> visited(board.size(),
                                 vector<bool>(board[0].size(), false));
    for (int i = 0; i < board.size(); i++) {
      dfs(board, visited, 0, i);
      dfs(board, visited, board[0].size() - 1, i);
    }
    for (int j = 0; j < board[0].size(); j++) {
      dfs(board, visited, j, 0);
      dfs(board, visited, j, board.size() - 1);
    }

    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (board[i][j] == 'O' && visited[i][j]) {
          // nop
        } else {
          board[i][j] = 'X';
        }
      }
    }
  }

private:
  void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int x,
           int y) {
    if (x < 0 || x >= board[0].size() || y < 0 || y >= board.size())
      return;

    if (board[y][x] == 'X' || visited[y][x])
      return;

    visited[y][x] = true;

    const int dirX[4] = {0, 1, 0, -1};
    const int dirY[4] = {1, 0, -1, 0};
    for (int i = 0; i < 4; i++) {
      int xx = x + dirX[i];
      int yy = y + dirY[i];
      dfs(board, visited, xx, yy);
    }
    return;
  }
};
