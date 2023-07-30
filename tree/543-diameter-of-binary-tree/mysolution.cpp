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
  int diameterOfBinaryTree(TreeNode *root) {
    int max_diam = INT_MIN;
    height(root, max_diam);
    return max_diam;
  }

public:
  int height(TreeNode *root, int &max_diam) {
    if (!root)
      return -1;

    const int hl = 1 + height(root->left, max_diam);
    const int hr = 1 + height(root->right, max_diam);
    max_diam = max(max_diam, hl + hr);

    return max(hl, hr);
  }
};
