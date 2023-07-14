// #include <queue>
// #include <unordered_map>
// #include <utility>
// #include <vector>
// class Solution {
// public:
//   std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
//     std::vector<int> ans;
//     std::unordered_map<int, int> map;

//     for (const auto &i : nums) {
//       map[i]++;
//     }

//     std::priority_queue<std::pair<int, int>>pq;
//     for (auto it = map.begin(); it != map.end(); it++) {
//       pq.push({it->second, it->first});
//     }

//     while (k-- && !pq.empty()) {
//       ans.push_back(pq.top().second);
//       pq.pop();
//     }

//     return ans;
//   }

// private:
//   struct Compare {
//     bool operator()(const std::pair<int, int> &a,
//                     const std::pair<int, int> &b) {
//       return a.first > b.first;
//     }
//   };
// };

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

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> pq;

    for (auto it = map.begin(); it != map.end(); it++) {
      pq.push({it->first, it->second});
    }

    while (k--  && !pq.empty()) {
      ans.push_back(pq.top().first);
      pq.pop();
    }

    return ans;
  }

private:
  struct Compare {
    bool operator()(const std::pair<int, int> &a,
                    const std::pair<int, int> &b) {
      return a.second < b.second;
    }
  };
};