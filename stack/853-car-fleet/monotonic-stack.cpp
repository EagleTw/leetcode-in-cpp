class Solution {
public:
  int carFleet(int target, vector<int> &position, vector<int> &speed) {
    int n = position.size();

    // sort the postion asending order
    vector<pair<int, int>> ps; // (position, speed)
    for (int i = 0; i < n; i++) {
      ps.push_back(make_pair(position[i], speed[i]));
    }
    sort(ps.begin(), ps.end());

    stack<float> monoStack;
    for (int i = 0; i < n; i++) {
      const float t = static_cast<float>(target - ps[i].first) / ps[i].second;
      while (!monoStack.empty() && t >= monoStack.top()) {
        monoStack.pop();
      }
      monoStack.push(t);
    }

    return monoStack.size();
  }
};