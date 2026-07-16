class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {

        int n = nums.size();

        // Window sums
        vector<int> window(n - k + 1);

        int sum = 0;

        for (int i = 0; i < n; i++) {

            sum += nums[i];

            if (i >= k)
                sum -= nums[i - k];

            if (i >= k - 1)
                window[i - k + 1] = sum;
        }

        int m = window.size();

        vector<int> left(m), right(m);

        // Best left
        int best = 0;

        for (int i = 0; i < m; i++) {

            if (window[i] > window[best])
                best = i;

            left[i] = best;
        }

        // Best right
        best = m - 1;

        for (int i = m - 1; i >= 0; i--) {

            if (window[i] >= window[best])
                best = i;

            right[i] = best;
        }

        vector<int> ans(3);

        int maxSum = 0;

        // Middle window
        for (int mid = k; mid < m - k; mid++) {

            int l = left[mid - k];
            int r = right[mid + k];

            int total = window[l] + window[mid] + window[r];

            if (total > maxSum) {

                maxSum = total;

                ans = {l, mid, r};
            }
        }

        return ans;
    }
};