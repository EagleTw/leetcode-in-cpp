// 花花 Topological sort
// https://zxi.mytechroad.com/blog/graph/leetcode-210-course-schedule-ii/
#include <vector>
class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {

    std::vector<std::vector<int>> graph(numCourses);

    // construct graph
    for (const auto &v : prerequisites) {
      graph[v[0]].push_back(v[1]);
    }

    // state: 0 == unknown, 1 == visting, 2 == visited
    std::vector<int> state(numCourses, 0);
    std::vector<int> ans;

    for (int i = 0; i < numCourses; i++) {
      if (dfs(graph, state, ans, i))
        return {};
    }

    std::reverse(ans.begin(), ans.end());
    return ans;
  }

private:
  bool dfs(std::vector<std::vector<int>> &graph, std::vector<int> &state,
           std::vector<int> &ans, int cur) {
    if (state[cur] == 1)
      return true;
    else if (state[cur] == 2)
      return false;

    state[cur] = 1;
    for (const auto &i : graph[cur]) {
      if (dfs(graph, state, ans, i))
        return true;
    }
    state[cur] = 2;
    ans.push_back(cur);

    return false;
  }
};