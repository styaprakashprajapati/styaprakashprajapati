class Solution {
public:
    int numDecodings(string s) {

        int n = s.size();

        if (s[0] == '0')
            return 0;

        vector<int> dp(n + 1, 0);

        // Empty string
        dp[0] = 1;

        // First character
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {

            // One digit
            int oneDigit = s[i - 1] - '0';

            if (oneDigit >= 1 && oneDigit <= 9) {
                dp[i] += dp[i - 1];
            }

            // Two digits
            int twoDigit = (s[i - 2] - '0') * 10
                         + (s[i - 1] - '0');

            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};