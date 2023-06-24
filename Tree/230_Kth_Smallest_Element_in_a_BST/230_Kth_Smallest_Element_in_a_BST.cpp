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

enum class color {WHITE = 0, BLACK};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {

        bool found_leftmost = false;
        int count = 0;
        std::stack<std::pair<color, TreeNode*>> s;  // (traced, node)
        s.push({color::WHITE, root});

        TreeNode* node = nullptr;
        // find the left-most node first
        while (!s.empty()) {
            node = s.top().second;
            color curColor = s.top().first;
            s.pop();

            if (!node)
                continue;

            if (!found_leftmost && !node->left) {
                found_leftmost = true;
            }

            if (curColor == color::WHITE) {
                if (node->right)
                    s.push({color::WHITE, node->right});
                s.push({color::BLACK, node});
                if (node->left)
                    s.push({color::WHITE, node->left});
            } else {
                if (found_leftmost) {
                count++;
                if (count == k)
                    return node->val;
                }
            }
        }
        return INT_MIN;
    }
};
