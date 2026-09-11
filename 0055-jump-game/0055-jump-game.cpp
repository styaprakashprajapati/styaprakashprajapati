class Solution {
public:
    bool canJump(vector<int>& nums) {

        int maxReach = 0;

        for (int i = 0; i < nums.size(); i++) {

            // Current index reachable nahi hai
            if (i > maxReach) {
                return false;
            }

            // Maximum reachable index update karo
            maxReach = max(maxReach, i + nums[i]);

            // Last index already reachable
            if (maxReach >= nums.size() - 1) {
                return true;
            }
        }

        return true;
    }
};