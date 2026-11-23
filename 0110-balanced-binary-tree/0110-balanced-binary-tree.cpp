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

    int height(TreeNode* root) {

        // Empty tree
        if (root == NULL) {
            return 0;
        }

        // Find left height
        int left = height(root->left);

        if (left == -1) {
            return -1;
        }

        // Find right height
        int right = height(root->right);

        if (right == -1) {
            return -1;
        }

        // Check balance condition
        if (abs(left - right) > 1) {
            return -1;
        }

        // Return height
        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {

        return height(root) != -1;
    }
};