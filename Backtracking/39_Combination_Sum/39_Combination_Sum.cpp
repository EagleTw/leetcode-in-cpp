class Solution {
 private:
  void helper(vector<int> candidates, int index, int target,
              vector<vector<int>>& ret, vector<int>& subset) {
    if (target < 0) return;

    if (target == 0) {
      ret.push_back(subset);
      return;
    }

    for (int i = index; i < candidates.size(); i++) {
      subset.push_back(candidates[i]);
      helper(candidates, i, target - candidates[i], ret, subset);
      subset.pop_back();
    }
  }

 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ret;
    vector<int> subset;
    helper(candidates, 0, target, ret, subset);
    return ret;
  }
};
