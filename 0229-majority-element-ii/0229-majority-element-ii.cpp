
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        vector<int> ans;

        int n = nums.size();

        for(int i = 0; i < n; i++) {

            int count = 0;

            // Check frequency
            for(int j = 0; j < n; j++) {

                if(nums[i] == nums[j]) {
                    count++;
                }
            }

            // Check if greater than n/3
            if(count > n / 3) {

                // Avoid duplicates
                if(find(ans.begin(), ans.end(), nums[i]) == ans.end()) {
                    ans.push_back(nums[i]);
                }
            }
        }

        return ans;
    }
};
