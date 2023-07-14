class Solution {
public:
  vector<int> decode(vector<int> &encoded, int first) {
    vector<int> ret;
    if (encoded.size() == 0) {
      return ret;
    }

    ret.push_back(first);

    for (int i = 0; i < encoded.size(); i++) {
      ret.push_back(ret[i] ^ encoded[i]);
    }
    return ret;
  }
};
