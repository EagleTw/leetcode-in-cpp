/* Need practice!
 *
 * Possible solution
 * 1. Brute force - O(m * n)
 * 2. Sort - O(m * logm)
 * 3. Counting sort O(26 * m)
 * 4. Hashmap O(26 * m)
 */
#include <string>
#include <vector>
class Solution {
public:
  bool checkInclusion(std::string s1, std::string s2) {
    if (s1.size() > s2.size())
      return false;

    std::vector<int> map1(26, 0), map2(26, 0);

    for (const auto &c : s1) {
      map1[c - 'a']++;
    }

    int i = 0, j = 0;
    while (j < s2.size()) {
      map2[s2[j] - 'a']++;
      if (j - i + 1 > s1.size()) {
        map2[s2[i] - 'a']--;
        i++;
      }
      if (map1 == map2) { // using default stl vecotr = operator
        return true;
      }
      j++;
    }
    return false;
  }
};
