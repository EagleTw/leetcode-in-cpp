// TLE
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
class TimeMap {
public:
  TimeMap() {}

  void set(std::string key, std::string value, int timestamp) {
    // ask the interviewer: whether insertion of timestamp is sorted
    map_[key].emplace_back(timestamp, std::move(value));
  }

  std::string get(std::string key, int timestamp) {
    auto it = map_.find(key);
    if (it == map_.end())
      return "";

    const auto v = it->second;
    int l = 0, r = v.size() - 1;
    while (l <= r) {
      const int mid = l + (r - l) / 2;
      const int ts = v[mid].first;
      if (ts == timestamp) {
        return v[mid].second;
      } else if (ts < timestamp) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return (r >= 0)? v[r].second : "";
  }

private:
  std::unordered_map<std::string, std::vector<std::pair<int, std::string>>>
      map_;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
