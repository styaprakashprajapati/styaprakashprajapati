class Solution {
public:
    int maxRemovals(string source,
                    string pattern,
                    vector<int>& targetIndices) {

        int n = source.size();
        int m = pattern.size();

        vector<bool> canRemove(n, false);

        for (int index : targetIndices) {
            canRemove[index] = true;
        }

        vector<vector<int>> dp(
            n + 1,
            vector<int>(m + 1, -1)
        );

        dp[0][0] = 0;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j <= m; j++) {

                if (dp[i][j] == -1) {
                    continue;
                }

                // Option 1: Remove current character
                if (canRemove[i]) {

                    dp[i + 1][j] =
                        max(dp[i + 1][j],
                            dp[i][j] + 1);
                }

                // Option 2: Keep current character
                dp[i + 1][j] =
                    max(dp[i + 1][j],
                        dp[i][j]);

                // Use current character for pattern
                if (j < m &&
                    source[i] == pattern[j]) {

                    dp[i + 1][j + 1] =
                        max(dp[i + 1][j + 1],
                            dp[i][j]);
                }
            }
        }

        return dp[n][m];
    }
};