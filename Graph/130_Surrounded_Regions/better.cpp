// inplace solution: by replacing visted vector, with changing board into 'T'
class Solution {
public:
  void solve(vector<vector<char>> &board) {
    for (int i = 0; i < board.size(); i++) {
      dfs(board, 0, i);
      dfs(board, board[0].size() - 1, i);
    }
    for (int j = 0; j < board[0].size(); j++) {
      dfs(board, j, 0);
      dfs(board, j, board.size() - 1);
    }

    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (board[i][j] != 'T') {
          board[i][j] = 'X';
        } else {
          board[i][j] = 'O';
        }
      }
    }
  }

private:
  void dfs(vector<vector<char>> &board, int x, int y) {
    if (x < 0 || x >= board[0].size() || y < 0 || y >= board.size())
      return;

    if (board[y][x] == 'X' || board[y][x] == 'T')
      return;

    board[y][x] = 'T';

    const int dirX[4] = {0, 1, 0, -1};
    const int dirY[4] = {1, 0, -1, 0};
    for (int i = 0; i < 4; i++) {
      int xx = x + dirX[i];
      int yy = y + dirY[i];
      dfs(board, xx, yy);
    }
    return;
  }
};
