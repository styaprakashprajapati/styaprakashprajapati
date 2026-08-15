class Solution {
public:

    void solve(vector<int>& nums, vector<int>& path,
               vector<vector<int>>& ans, vector<bool>& used) {

        // Agar path ki length nums ke equal hai,
        // to ek complete permutation mil gaya
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }

        // Har number ko try karo
        for (int i = 0; i < nums.size(); i++) {

            // Agar number already use ho chuka hai
            // to skip karo
            if (used[i])
                continue;

            // Choose
            used[i] = true;
            path.push_back(nums[i]);

            // Explore
            solve(nums, path, ans, used);

            // Backtrack (Undo)
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> path;
        vector<bool> used(nums.size(), false);

        solve(nums, path, ans, used);

        return ans;
    }
};