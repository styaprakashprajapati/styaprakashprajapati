class Solution {
public:

    void solve(vector<int>& nums,
               vector<bool>& used,
               vector<int>& current,
               vector<vector<int>>& ans) {

        // Complete permutation
        if (current.size() == nums.size()) {
            ans.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            // Already used
            if (used[i]) {
                continue;
            }

            // Skip duplicate at same level
            if (i > 0 &&
                nums[i] == nums[i - 1] &&
                !used[i - 1]) {

                continue;
            }

            // Choose
            used[i] = true;
            current.push_back(nums[i]);

            // Explore
            solve(nums, used, current, ans);

            // Backtrack
            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> current;
        vector<bool> used(nums.size(), false);

        solve(nums, used, current, ans);

        return ans;
    }
};