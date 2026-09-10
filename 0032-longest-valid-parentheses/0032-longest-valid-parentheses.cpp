class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int> st;

        st.push(-1);

        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            // Opening bracket
            if (s[i] == '(') {
                st.push(i);
            }

            // Closing bracket
            else {

                st.pop();

                // No matching '('
                if (st.empty()) {
                    st.push(i);
                }

                // Valid parentheses found
                else {
                    ans = max(ans, i - st.top());
                }
            }
        }

        return ans;
    }
};