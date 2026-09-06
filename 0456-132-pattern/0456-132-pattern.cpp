class Solution {
public:
    bool find132pattern(vector<int>& nums) {

        int n = nums.size();

        if (n < 3)
            return false;

        stack<int> st;

        // This stores the possible "2" of 132
        int second = INT_MIN;

        // Right to left
        for (int i = n - 1; i >= 0; i--) {

            // nums[i] can be "1"
            if (nums[i] < second)
                return true;

            // Find a suitable "2"
            while (!st.empty() && nums[i] > st.top()) {
                second = st.top();
                st.pop();
            }

            st.push(nums[i]);
        }

        return false;
    }
};