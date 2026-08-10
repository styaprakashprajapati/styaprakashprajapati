class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int leftMax = nums[0];
        int currentMax = nums[0];

        int partition = 1;

        for (int i = 1; i < nums.size(); i++) {

            currentMax = max(currentMax, nums[i]);

            // Current element cannot stay in right part
            if (nums[i] < leftMax) {
                leftMax = currentMax;
                partition = i + 1;
            }
        }

        return partition;
    }
};