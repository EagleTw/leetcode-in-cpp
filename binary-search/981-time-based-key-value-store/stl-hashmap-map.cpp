#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
class TimeMap {
public:
  TimeMap() {}

  void set(std::string key, std::string value, int timestamp) {
    map_[key].emplace(timestamp, std::move(value));
  }

  std::string get(std::string key, int timestamp) {
    auto it = map_.find(key);
    if (it == map_.end())
      return "";

    auto p = it->second.lower_bound(timestamp);
    if (p == it->second.end())
      return "";

    return p->second;
  }

private:
  std::unordered_map<std::string, std::map<int, std::string, std::greater<int>>>
      map_;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
