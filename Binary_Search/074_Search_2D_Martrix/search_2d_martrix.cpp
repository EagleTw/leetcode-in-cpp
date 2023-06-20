class Solution {
public:

  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix[0].size();
    int n = matrix.size();
    int l = 0;
    int r = m * n -1;

    while (l <= r) {
      int mid = (l + r) / 2;
      if (matrix[mid / m][mid % n] == target) {
        return true;
      } else if (matrix[mid / m][mid % n] < target) {
        l = mid++;
      } else {
        r = mid--;
      }
    }
    return false;
  }
};
