#include <vector>
class Solution {
public:
  std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> ans;
    std::string s;

    backtrack(ans, n, s, 0, 0);
    return ans;
  }

private:
  void backtrack(std::vector<std::string> &ans, int n, std::string &s,
                 int leftN, int rightN) {
    if (leftN == n && rightN == n) {
      ans.push_back(s);
      return;
    }

    if (leftN < n) {
      s.push_back('(');
      backtrack(ans, n, s, leftN + 1, rightN);
      s.pop_back();
    }

    if (leftN > rightN) { // if '(' is more than ')', we can add ')'
      s.push_back(')');
      backtrack(ans, n, s, leftN, rightN + 1);
      s.pop_back();
    }
  }
};