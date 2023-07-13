#include <vector>
class Solution {
public:
  bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {
    // construct a graph
    std::vector<std::vector<int>> graph(numCourses);

    for (const auto &v : prerequisites) {
      graph[v[0]].push_back(v[1]);
    }

    // state: 0 == unknown
    //        1 == visiting
    //        2 == visited
    std::vector<int> state(numCourses, 0);
    for (int i = 0; i < numCourses; i++) {
      if (dfs(i, graph, state))
        return false;
    }

    return true;
  }
private:

  // topological sort
  // return true, if we found a cycle
  bool dfs(int cur, std::vector<std::vector<int>> &graph, std::vector<int> &v) {
    if (v[cur] == 1)
      return true;
    else if (v[cur] == 2)
      return false;

    v[cur] = 1;
    for (const int t : graph[cur]) {
      if (dfs(t, graph, v))
        return true;
    }
    v[cur] = 2;

    return false;
  }
};