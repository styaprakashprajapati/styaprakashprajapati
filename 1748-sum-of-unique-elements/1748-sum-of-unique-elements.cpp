class Solution {
public:
    int sumOfUnique(vector<int>& nums) {

        unordered_map<int, int> freq;

        // Count frequency
        for (int num : nums) {
            freq[num]++;
        }

        int sum = 0;

        // Add only unique numbers
        for (int num : nums) {

            if (freq[num] == 1) {
                sum += num;
            }
        }

        return sum;
    }
};