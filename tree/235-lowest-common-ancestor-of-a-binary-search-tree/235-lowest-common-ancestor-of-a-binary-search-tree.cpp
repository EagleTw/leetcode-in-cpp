class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* node = root;
    while (node) {
      if (p->val > node->val && q->val > node->val)
        node = node->right;
      else if (p->val < node->val && q->val < node->val)
        node = node->left;
      else
        break;
    }
    return node;
  }
};
