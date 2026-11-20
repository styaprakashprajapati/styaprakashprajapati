class Solution {
public:
    int MOD = 1e9 + 7;

    int dp[51][51][51];

    int solve(int m, int n, int r, int c, int moves) {

        // Ball grid ke bahar chali gayi
        if (r < 0 || c < 0 || r >= m || c >= n) {
            return 1;
        }

        // Moves khatam
        if (moves == 0) {
            return 0;
        }

        // Already calculated
        if (dp[r][c][moves] != -1) {
            return dp[r][c][moves];
        }

        long long ans = 0;

        // Up
        ans += solve(m, n, r - 1, c, moves - 1);

        // Down
        ans += solve(m, n, r + 1, c, moves - 1);

        // Left
        ans += solve(m, n, r, c - 1, moves - 1);

        // Right
        ans += solve(m, n, r, c + 1, moves - 1);

        return dp[r][c][moves] = ans % MOD;
    }

    int findPaths(int m, int n, int maxMove,
                  int startRow, int startColumn) {

        memset(dp, -1, sizeof(dp));

        return solve(m, n, startRow, startColumn, maxMove);
    }
};