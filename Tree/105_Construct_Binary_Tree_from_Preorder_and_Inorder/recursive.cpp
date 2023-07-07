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
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return recurBuild(preorder, 0, preorder.size() - 1, inorder, 0,
                      inorder.size() - 1);
  }

private:
  TreeNode *recurBuild(vector<int> &preorder, int pre_start, int pre_end,
                       vector<int> &inorder, int in_start, int in_end) {

    if ((pre_end - pre_start) != (in_end - in_start))
      assert(0);

    if ((pre_start > pre_end) || (in_start > in_end))
      return nullptr;

    TreeNode *root = new TreeNode(preorder[pre_start]);

    int in_off = 0;
    for (int i = in_start; i <= in_end; i++) {
      if (inorder[i] == preorder[pre_start]) {
        break;
      }
      in_off++;
    }
    in_off--;

    root->left = recurBuild(preorder, pre_start + 1, pre_start + 1 + in_off,
                            inorder, in_start, in_start + in_off);
    root->right = recurBuild(preorder, pre_start + in_off + 2, pre_end, inorder,
                             in_start + in_off + 2, in_end);

    return root;
  }
};
