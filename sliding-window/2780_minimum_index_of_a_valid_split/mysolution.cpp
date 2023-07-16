// Weekly Contest 354 : TLE
// Problem:
//   TC is O(n^2) in my solution. but it can actuallly be O(n)
class Solution {
public:
  int minimumIndex(vector<int> &nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
      if (validSplit(nums, i))
        return i;
    }
    // validSplit(nums, 2);

    return -1;
  }

private:
  bool validSplit(vector<int> &nums, int splitIndex) {
    std::map<int, int> loC;
    std::map<int, int> hiC;

    for (int i = 0; i < nums.size(); i++) {
      if (i <= splitIndex)
        loC[nums[i]]++;
      else
        hiC[nums[i]]++;
    }

    int maxLo = -1;
    int maxLoFreq = -1;
    int maxHi = -1;
    int maxHiFreq = -1;
    for (auto it : loC) {
      if (it.second > maxLoFreq) {
        maxLoFreq = it.second;
        maxLo = it.first;
      }
    }

    for (auto it : hiC) {
      if (it.second > maxHiFreq) {
        maxHiFreq = it.second;
        maxHi = it.first;
      }
    }

    if (maxLo != maxHi) {
      return false;
    }
    if (maxLoFreq * 2 <= (splitIndex + 1) ||
        maxHiFreq * 2 <= (nums.size() - splitIndex - 1)) {
      return false;
    }

    return true;
  }
};
