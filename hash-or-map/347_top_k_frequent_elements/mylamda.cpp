#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
class Solution {
public:
  std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
    std::vector<int> ans;
    std::unordered_map<int, int> map;

    for (const auto &i : nums) {
      map[i]++;
    }

    const auto comp = [=](std::pair<int, int> a, std::pair<int, int> b) {
      return a.second < b.second;
    };

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        decltype(comp)>
        pq{comp}; // "error: no matching constructor for initialization of
                  // 'std::priority_queue"
                  //  if the last {comp} is removed

    for (auto it = map.begin(); it != map.end(); it++) {
      pq.push({it->first, it->second});
    }

    while (k-- && !pq.empty()) {
      ans.push_back(pq.top().first);
      pq.pop();
    }

    return ans;
  }
};