class Solution {
public:

    void solve(int start, int n, int k,
               vector<int>& path,
               vector<vector<int>>& ans) {

        if (path.size() == k) {
            ans.push_back(path);
            return;
        }

        int need = k - path.size();

        for (int i = start; i <= n - need + 1; i++) {

            path.push_back(i);

            solve(i + 1, n, k, path, ans);

            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> ans;
        vector<int> path;

        solve(1, n, k, path, ans);

        return ans;
    }
};