// very slow (beats 6.01 %)
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    for (int i = 0; i < temperatures.size(); i++) {
      while (!pq.empty() && pq.top().first < temperatures[i]) {
        temperatures[pq.top().second] = i - pq.top().second;
        pq.pop();
      }
      pq.push({temperatures[i], i});
    }

    while (!pq.empty()) {
      temperatures[pq.top().second] = 0;
      pq.pop();
    }

    return temperatures;
  }
};
