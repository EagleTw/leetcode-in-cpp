class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> hash;
    stack<int> st;
    for (int i = 0; i < nums2.size(); i++) {
      while (!st.empty() && st.top() < nums2[i]) {
        hash[st.top()] = nums2[i];
        st.pop();
      }
      st.push(nums2[i]);
    }

    while (!st.empty()) {
      hash[st.top()] = -1;
      st.pop();
    }

    vector<int> ans(nums1.size(), -1);
    for (int i = 0; i < nums1.size(); i++) {
      if (hash.count(nums1[i])) {
        ans[i] = hash[nums1[i]];
      }
    }

    return ans;
  }
};
