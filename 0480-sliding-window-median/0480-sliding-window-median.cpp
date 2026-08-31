class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k / 2);

        vector<double> ans;

        for (int i = k;; i++) {

            // Median nikalo
            if (k % 2 == 1)
                ans.push_back((double)*mid);
            else
                ans.push_back(((double)*mid + *prev(mid)) / 2.0);

            if (i == nums.size())
                break;

            // Naya number insert
            window.insert(nums[i]);

            if (nums[i] < *mid)
                mid--;

            // Purana number remove
            if (nums[i - k] <= *mid)
                mid++;

            window.erase(window.lower_bound(nums[i - k]));
        }

        return ans;
    }
};