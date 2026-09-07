class Solution {
public:

    int ans = 0;

    void solve(int row, int n,
               vector<bool>& col,
               vector<bool>& diag1,
               vector<bool>& diag2) {

        // All queens placed
        if (row == n) {
            ans++;
            return;
        }

        for (int c = 0; c < n; c++) {

            // Check whether this position is safe
            if (col[c])
                continue;

            // Main diagonal: row - col
            int d1 = row - c + n - 1;

            // Anti-diagonal: row + col
            int d2 = row + c;

            if (diag1[d1] || diag2[d2])
                continue;

            // Place queen
            col[c] = true;
            diag1[d1] = true;
            diag2[d2] = true;

            solve(row + 1, n, col, diag1, diag2);

            // Backtrack
            col[c] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }

    int totalNQueens(int n) {

        vector<bool> col(n, false);

        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);

        solve(0, n, col, diag1, diag2);

        return ans;
    }
};