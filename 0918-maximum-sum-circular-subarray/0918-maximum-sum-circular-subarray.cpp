class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int totalSum = 0;

        int currMax = nums[0];
        int maxSum = nums[0];

        int currMin = nums[0];
        int minSum = nums[0];

        for (int i = 0; i < nums.size(); i++) {

            totalSum += nums[i];

            if (i > 0) {
                // Maximum Kadane
                currMax = max(nums[i], currMax + nums[i]);
                maxSum = max(maxSum, currMax);

                // Minimum Kadane
                currMin = min(nums[i], currMin + nums[i]);
                minSum = min(minSum, currMin);
            }
        }

        // Agar sab elements negative hain
        if (maxSum < 0)
            return maxSum;

        return max(maxSum, totalSum - minSum);
    }
};