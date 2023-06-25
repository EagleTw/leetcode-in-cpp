// 小心!
// 如果是 INT_MIN & INT_MAX 會 fail cornercase 2^32-1
class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    if (!root) return true;

    return validSubTree(root, nullptr, nullptr);
  }

  bool validSubTree(TreeNode* root, TreeNode* upper, TreeNode* lower) {
    if (!root) return true;

    if ((upper && lower) &&
        (root->val >= upper->val || root->val <= lower->val))
      return false;

    if (root->left) {
      if (root->val <= root->left->val) return false;
    }
    if (root->right) {
      if (root->val >= root->right->val) return false;
    }

    return validSubTree(root->left, root, lower) &&
           validSubTree(root->right, upper, root);
  }
};
