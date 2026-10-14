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
    bool hasPathSum(TreeNode* root, int targetSum) {

        // Empty tree
        if (root == nullptr) {
            return false;
        }

        // Leaf node
        if (root->left == nullptr &&
            root->right == nullptr) {
            return targetSum == root->val;
        }

        // Current node ki value subtract karo
        targetSum -= root->val;

        // Left ya right mein valid path dhoondo
        return hasPathSum(root->left, targetSum) ||
               hasPathSum(root->right, targetSum);
    }
};
