class Solution {
 private:
  static inline bool out_of_bound(vector<vector<char>>& board, int x, int y) {
    if (x < 0 || y < 0 || (x > board[0].size() - 1) || (y > board.size() - 1))
      return true;
    return false;
  }

  static bool backtrack_board(vector<vector<char>>& board, int x, int y,
                              int depth, string& word) {
    if (out_of_bound(board, x, y) || board[y][x] != word[depth] ||
        depth >= word.size())
      return false;

    if (depth == word.size() - 1) return true;

    char tmp = board[y][x];
    board[y][x] = '*';

    bool ret = backtrack_board(board, x + 1, y, depth + 1, word) ||
               backtrack_board(board, x - 1, y, depth + 1, word) ||
               backtrack_board(board, x, y + 1, depth + 1, word) ||
               backtrack_board(board, x, y - 1, depth + 1, word);

    board[y][x] = tmp;
    return ret;
  }

 public:
  bool exist(vector<vector<char>>& board, string word) {
    int board_size_x = board[0].size();
    int board_size_y = board.size();
    bool ret = false;

    for (int i = 0; i < board_size_x; i++) {
      for (int j = 0; j < board_size_y; j++) {
        if (backtrack_board(board, i, j, 0, word)) return true;
      }
    }
    return false;
  }
};
