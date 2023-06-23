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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::queue<TreeNode*> queue;
        queue.push(p);
        queue.push(q);

        while (!queue.empty()) {
            TreeNode *n1 = queue.front();
            queue.pop();
            TreeNode *n2 = queue.front();
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
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot)
            return true;
        if (!root)
            return false;

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();

            if (node == nullptr)
                continue;
            if (isSameTree(node, subRoot))
                return true;

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        return false;
    }
};
