#include <array>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
class Solution {
public:
  std::vector<std::vector<std::string>>
  accountsMerge(std::vector<std::vector<std::string>> &accounts) {
    // initialize union-find parent
    std::vector<int> parent(accounts.size(), -1);
    for (int i = 0; i < parent.size(); i++) {
      parent[i] = i;
    }

    // add all emails to hashmap
    std::unordered_map<std::string, int> map; // key: account, value: array_pos
    for (int i = 0; i < accounts.size(); i++) {
      for (auto it = accounts[i].begin() + 1; it != accounts[i].end(); it++) {
        auto it_m = map.find(*it);
        if (it_m == map.end()) {
          map.insert({*it, i});
        } else {
          // same email address
          int pa = find(parent, it_m->second); // array pos in map
          int pb = find(parent, i);            // new add
          if (pa != pb) {
            parent[pb] = pa;
          }
        }
      }
    }

    // find unique parent in parent array
    std::set<int> s;
    for (const auto pa : parent) {
      s.insert(find(parent, pa));
    }

    // out array
    // std::vector<int>

    return {};
  }

private:
  int find(std::vector<int> &parent, int a) {
    if (parent[a] != a)
      find(parent, parent[a]);
    return a;
  }
};
