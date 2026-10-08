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

    bool check(TreeNode* left, TreeNode* right) {

        // Dono NULL hain
        if (left == nullptr && right == nullptr) {
            return true;
        }

        // Sirf ek NULL hai
        if (left == nullptr || right == nullptr) {
            return false;
        }

        // Values different hain
        if (left->val != right->val) {
            return false;
        }

        // Mirror check
        return check(left->left, right->right) &&
               check(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {

        if (root == nullptr) {
            return true;
        }

        return check(root->left, root->right);
    }
};