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
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};

        vector<int> ret;
        int search_level = 0;
        std::stack<std::pair<int, TreeNode*>> s;
        s.push({0, root});

        while (!s.empty()) {
            TreeNode* node = s.top().second;
            int curr_level = s.top().first;
            s.pop();

            if (node->left)
                s.push({curr_level + 1, node->left});
            if (node->right)
                s.push({curr_level + 1, node->right});

            if (curr_level < search_level)
                continue;
            ret.push_back(node->val);
            search_level++;
        }
        return ret;
    }
};
