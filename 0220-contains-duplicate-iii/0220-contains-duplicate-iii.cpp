class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        
        if (indexDiff <= 0 || valueDiff < 0)
            return false;

        set<long long> window;

        for (int i = 0; i < nums.size(); i++) {

            // Find first number >= nums[i] - valueDiff
            auto it = window.lower_bound((long long)nums[i] - valueDiff);

            // Check if it is <= nums[i] + valueDiff
            if (it != window.end() &&
                *it <= (long long)nums[i] + valueDiff) {
                return true;
            }

            // Add current number
            window.insert(nums[i]);

            // Keep only indexDiff previous elements
            if (i >= indexDiff) {
                window.erase(nums[i - indexDiff]);
            }
        }

        return false;
    }
};