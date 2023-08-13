class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    unordered_map<int, int> mp;
    // x dirction
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (board[i][j] == '.') {
          ; // do nothing
        } else {
          mp[board[i][j]]++;
          if (mp[board[i][j]] > 1)
            return false;
        }
      }
      mp.clear();
    }

    // y direction
    for (int j = 0; j < board[0].size(); j++) {
      for (int i = 0; i < board.size(); i++) {
        if (board[i][j] == '.') {
          ; // do nothing
        } else {
          mp[board[i][j]]++;
          if (mp[board[i][j]] > 1)
            return false;
        }
      }
      mp.clear();
    }

    // 3 x 3 grid
    for (int x = 0; x < board.size(); x += 3) {
      for (int y = 0; y < board.size(); y += 3) {
        for (int i = x; i < x + 3; i++) {
          for (int j = y; j < y + 3; j++) {
            if (board[i][j] == '.') {
              ; // do nothing
            } else {
              mp[board[i][j]]++;
              if (mp[board[i][j]] > 1)
                return false;
            }
          }
        }
        mp.clear();
      }
    }

    return true;
  }
};
