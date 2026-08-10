class Solution {
public:
    int search(vector<int>& nums, int target) {

        int st = 0;
        int end = nums.size() - 1;

        while (st <= end) {

            int mid = st + (end - st) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                // Target right side mein hai
                st = mid + 1;
            }
            else {
                // Target left side mein hai
                end = mid - 1;
            }
        }

        return -1;
    }
};