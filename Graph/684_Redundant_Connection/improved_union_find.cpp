// union find
// self implemented with vector
#include <vector>
class Solution {
public:
  std::vector<int>
  findRedundantConnection(std::vector<std::vector<int>> &edges) {
    int n = edges.size();
    std::vector<int> parent(n + 1, 0);
    int color = 0;

    // set every parent to itself
    for (int i = 0; i <= n; i++) {
      parent[i] = i;
    }

    for (const auto &e : edges) {
      int p1 = find(parent, e[0]);
      int p2 = find(parent, e[1]);
      if (p1 != p2) {
        parent[p1] = p2;
      } else {
        return e;
      }
    }
    return {};
  }

private:
  int find(std::vector<int> &parent, int x) {
    return parent[x] == x ? x : find(parent, parent[x]);
  }
};