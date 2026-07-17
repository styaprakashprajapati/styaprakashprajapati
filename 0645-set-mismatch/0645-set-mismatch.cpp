class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        int duplicate = -1;
        int missing = -1;

        for (int i = 0; i < nums.size(); i++) {

            int index = abs(nums[i]) - 1;

            if (nums[index] < 0) {
                duplicate = abs(nums[i]);
            } else {
                nums[index] *= -1;
            }
        }

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] > 0) {
                missing = i + 1;
                break;
            }
        }

        return {duplicate, missing};
    }
};