// union find
// self implemented with vector
#include <vector>
class Solution {
public:
  std::vector<int>
  findRedundantConnection(std::vector<std::vector<int>> &edges) {
    int n = edges.size();
    std::vector<int> visited(n + 1, 0);
    int color = 0;

    for (const auto &e : edges) {
      if (!visited[e[0]] && !visited[e[1]]) {
        color++;
        visited[e[0]] = color;
        visited[e[1]] = color;
      } else if (!visited[e[0]] || !visited[e[1]]) {
        if (!visited[e[0]])
          visited[e[0]] = visited[e[1]];
        else
          visited[e[1]] = visited[e[0]];
      } else if (visited[e[0]] == visited[e[1]]) {
        // cycle exsites
        return e;
      } else if (visited[e[0]] != visited[e[1]]) {
        // union
        color++;
        int color1 = visited[e[0]];
        int color2 = visited[e[1]];
        for (int &i : visited) {
          if (i == color1 || i == color2)
            i = color;
        }
      }
    }
    return {};
  }
};