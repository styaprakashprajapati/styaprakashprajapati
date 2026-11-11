
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        vector<string> ans;

        int n = nums.size();

        int start = 0;

        for(int i = 0; i < n; i++) {

            // Check if range ends
            if(i == n - 1 || nums[i] + 1 != nums[i + 1]) {

                // Single number
                if(start == i) {
                    ans.push_back(to_string(nums[i]));
                }

                // Range of numbers
                else {
                    ans.push_back(
                        to_string(nums[start]) + "->" +
                        to_string(nums[i])
                    );
                }

                // Start next range
                start = i + 1;
            }
        }

        return ans;
    }
};
