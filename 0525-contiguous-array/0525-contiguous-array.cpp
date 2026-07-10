class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        unordered_map<int, int> mp;
        mp[0] = -1;

        int sum = 0;
        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == 0)
                sum += -1;
            else
                sum += 1;

            if (mp.find(sum) != mp.end()) {

                maxLen = max(maxLen, i - mp[sum]);

            } else {

                // Store only the first occurrence
                mp[sum] = i;
            }
        }

        return maxLen;
    }
};