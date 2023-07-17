// dfs + backtracking

#include <vector>
class Solution {
public:
  std::vector<std::vector<int>>
  allPathsSourceTarget(std::vector<std::vector<int>> &graph) {
    std::vector<std::vector<int>> ans;
    std::vector<int> path(1, 0);
    dfs(graph, ans, path, 0, graph.size() - 1);
    return ans;
  }

private:
  void dfs(std::vector<std::vector<int>> &graph,
           std::vector<std::vector<int>> &ans, std::vector<int> &path, int cur,
           int dest) {
    // terminate situation
    if (cur == dest) {    // cleaner way: `if (path.back() == graph.size() - 1)`
      ans.push_back(path);
      return;
    }
    // loop through all siblings
    for (const int &next : graph[cur]) {
      path.emplace_back(next);
      dfs(graph, ans, path, next, dest);
      path.pop_back();
    }
  }
};
