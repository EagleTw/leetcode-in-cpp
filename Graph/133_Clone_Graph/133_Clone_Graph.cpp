/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// Recursive bfs with map
class Solution {
public:
  Node *cloneGraph(Node *node) {
    if (!node)
      return nullptr;

    std::unordered_map<Node *, Node *> map;
    Node *ret = bfs(node, map);

    return ret;
  }

private:
  Node *bfs(Node *orig, std::unordered_map<Node *, Node *> &map) {
    if (!orig)
      return nullptr;

    Node *clone = new Node();
    map.insert({orig, clone});
    clone->val = orig->val;

    std::vector<Node *> cloneNeighbours;

    for (Node *n : orig->neighbors) {
      if (map.find(n) != map.end()) {
        cloneNeighbours.push_back(map[n]);
      } else {
        Node *tmp = bfs(n, map);
        cloneNeighbours.push_back(tmp);
      }
    }
    clone->neighbors = cloneNeighbours;

    return clone;
  }
};
