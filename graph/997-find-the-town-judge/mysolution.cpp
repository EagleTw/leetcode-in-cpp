#include <algorithm>
#include <vector>
class Solution {
public:
  int findJudge(int n, std::vector<std::vector<int>> &trust) {
    std::vector<std::vector<int>> graph(n + 1, std::vector<int>());

    for (const auto &v : trust) {
      graph[v.front()].emplace_back(v.back());
    }

    // find no trust
    int judge = 0;
    for (int i = 1; i < n + 1; i++) {
      if (graph[i].empty())
        judge = i;
    }

    // check if every other trust judge
    for (int i = 1; i < n + 1 && i != judge; i++) {
      bool found = false;
      for (auto num : graph[i]) {
        if (num == judge)
          found = true;
      }
      if (!found)
        return -1;
    }

    return judge;
  }
};
