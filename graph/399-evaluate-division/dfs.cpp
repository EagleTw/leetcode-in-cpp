// Good technique : O(n) finding time using 2-D hash table
// However, not fast enough, we can use union find to impove
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
class Solution {
public:
  std::vector<double>
  calcEquation(std::vector<std::vector<std::string>> &equations,
               std::vector<double> &values,
               std::vector<std::vector<std::string>> &queries) {
    // create hash table for string
    std::unordered_map<std::string, std::unordered_map<std::string, double>>
        graph;
    for (int i = 0; i < equations.size(); i++) {
      const std::string &s = equations[i].front(); // source
      const std::string &d = equations[i].back();  // destination
      const double val = values[i];
      graph[s][d] = val;
      graph[d][s] = 1.0 / val;
    }

    // add calculated to ans
    std::vector<double> ans;
    for (const auto &sd_pair : queries) {
      const std::string &s = sd_pair.front();
      const std::string &d = sd_pair.back();
      if (!graph.count(s) || !graph.count(d)) { // unordered_map::count
                                                // return 1 if found elem
        ans.emplace_back(-1.0);
        continue;
      }
      std::unordered_set<std::string> visited;
      ans.emplace_back(dfs(graph, visited, s, d));
    }

    return ans;
  }

private:
  double dfs(std::unordered_map<std::string,
                                std::unordered_map<std::string, double>> &graph,
             std::unordered_set<std::string> &visited, const std::string &src,
             const std::string &dest) {
    if (src == dest)
      return 1.0;

    visited.insert(src);

    for (const auto &next : graph[src]) {
      const std::string &c = next.first;
      if (visited.count(c)) // std::set::count, return 1 if found
        continue;
      double d = dfs(graph, visited, c, dest);
      if (d > 0)
        return d * graph[src][c];
    }
    return -1.0;
  }
};
