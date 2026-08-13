class Solution {
public:

    vector<vector<int>> ans;
    vector<int> current;

    void solve(vector<int>& nums, int index) {

        // Current subset ko answer mein add karo
        ans.push_back(current);

        // Aage ke elements try karo
        for (int i = index; i < nums.size(); i++) {

            // Element choose karo
            current.push_back(nums[i]);

            // Next element par jao
            solve(nums, i + 1);

            // Choice undo karo
            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        solve(nums, 0);

        return ans;
    }
};