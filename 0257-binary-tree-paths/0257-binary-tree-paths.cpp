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
    void dfs(TreeNode* root, string path, vector<string>& ans) {

        if (root == nullptr)
            return;

        // Current node ko path mein add karo
        if (path.empty())
            path = to_string(root->val);
        else
            path += "->" + to_string(root->val);

        // Leaf node
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(path);
            return;
        }

        // Left subtree
        dfs(root->left, path, ans);

        // Right subtree
        dfs(root->right, path, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> ans;

        dfs(root, "", ans);

        return ans;
    }
};