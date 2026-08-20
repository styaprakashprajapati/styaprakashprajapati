class Solution {
public:
    void reverse(vector<int>& nums, int left, int right) {

        while(left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }

    void rotate(vector<int>& nums, int k) {

        int n = nums.size();

        k = k % n;

        // Step 1
        reverse(nums, 0, n - 1);

        // Step 2
        reverse(nums, 0, k - 1);

        // Step 3
        reverse(nums, k, n - 1);
    }
};