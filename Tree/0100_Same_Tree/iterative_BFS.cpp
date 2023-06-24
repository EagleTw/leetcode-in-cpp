/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    std::queue<TreeNode*> queue;
    queue.push(p);
    queue.push(q);

    while (!queue.empty()) {
      TreeNode* n1 = queue.front();
      queue.pop();
      TreeNode* n2 = queue.front();
      queue.pop();

      if (!n1 && !n2)
        continue;
      else if (!n1 || !n2)
        return false;
      else if (n1->val != n2->val)
        return false;

      queue.push(n1->left);
      queue.push(n2->left);
      queue.push(n1->right);
      queue.push(n2->right);
    }
    return true;
  }
};
