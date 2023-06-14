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
    public: int minDifference = INT_MAX;
    TreeNode * prev;

    void f(TreeNode * node) {
        if (node == NULL) {
            return;
        }

        f(node -> left);
        if (prev != NULL) {
            minDifference = min(minDifference, abs(prev -> val - node -> val));
        }
        prev = node;
        f(node -> right);

    }

    int getMinimumDifference(TreeNode * root) {
        f(root);
        return minDifference;
    }
};
