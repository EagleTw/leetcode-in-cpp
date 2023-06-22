/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int height(TreeNode *root, bool *balanced) {
        if (!root)
            return 0;
        if (!balanced)
            return -1;

        int h_left = height(root->left, balanced);
        int h_right = height(root->right, balanced);
        int diff = std::abs(h_left - h_right);

        if (diff > 1) {
            *balanced = false;
            return -1;
        }
        return 1 + std::max(h_left, h_right);
    }

public:
    bool isBalanced(TreeNode* root) {
        bool ret = true;

        height(root, &ret);
        return ret;
    }
};
