class Solution {
public:

    vector<vector<int>> ans;
    vector<int> current;

    void solve(vector<int>& nums, int index) {

        // Current subset answer mein add karo
        ans.push_back(current);

        for (int i = index; i < nums.size(); i++) {

            // Same level par duplicate skip karo
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }

            // Choose
            current.push_back(nums[i]);

            // Next index par jao
            solve(nums, i + 1);

            // Undo choice
            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        // Duplicate elements ko paas lao
        sort(nums.begin(), nums.end());

        solve(nums, 0);

        return ans;
    }
};