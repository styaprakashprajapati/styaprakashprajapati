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

    vector<TreeNode*> generate(int start, int end) {

        vector<TreeNode*> result;

        // Empty tree
        if (start > end) {
            result.push_back(nullptr);
            return result;
        }

        // Har value ko root banao
        for (int rootValue = start; rootValue <= end; rootValue++) {

            // Left subtree ke saare possibilities
            vector<TreeNode*> leftTrees =
                generate(start, rootValue - 1);

            // Right subtree ke saare possibilities
            vector<TreeNode*> rightTrees =
                generate(rootValue + 1, end);

            // Har left tree + har right tree
            for (TreeNode* leftTree : leftTrees) {

                for (TreeNode* rightTree : rightTrees) {

                    TreeNode* root = new TreeNode(rootValue);

                    root->left = leftTree;
                    root->right = rightTree;

                    result.push_back(root);
                }
            }
        }

        return result;
    }

    vector<TreeNode*> generateTrees(int n) {

        if (n == 0) {
            return {};
        }

        return generate(1, n);
    }
};