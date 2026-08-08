class Solution {
public:
    int triangleNumber(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int ans = 0;

        for (int i = 2; i < n; i++) {

            int left = 0;
            int right = i - 1;

            while (left < right) {

                if (nums[left] + nums[right] > nums[i]) {

                    // All elements from left to right-1
                    // can form a valid triangle
                    ans += right - left;

                    right--;
                }
                else {

                    // Sum is too small
                    left++;
                }
            }
        }

        return ans;
    }
};