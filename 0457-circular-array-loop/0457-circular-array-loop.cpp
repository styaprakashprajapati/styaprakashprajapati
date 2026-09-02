class Solution {
public:
    int nextIndex(vector<int>& nums, int index) {
        int n = nums.size();

        return ((index + nums[index]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for (int start = 0; start < n; start++) {

            int slow = start;
            int fast = start;

            // Direction of starting element
            bool direction = nums[start] > 0;

            while (true) {

                // Slow ka next
                int nextSlow = nextIndex(nums, slow);

                // Check direction
                if ((nums[slow] > 0) != direction)
                    break;

                // Single element cycle check
                if (nextSlow == slow)
                    break;

                // Fast ka first move
                int nextFast = nextIndex(nums, fast);

                if ((nums[fast] > 0) != direction)
                    break;

                // Fast ka second move
                int nextFast2 = nextIndex(nums, nextFast);

                if ((nums[nextFast] > 0) != direction)
                    break;

                if (nextFast2 == nextFast)
                    break;

                slow = nextSlow;
                fast = nextFast2;

                // Cycle found
                if (slow == fast)
                    return true;
            }
        }

        return false;
    }
};