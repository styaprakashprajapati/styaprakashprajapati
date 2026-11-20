class Solution {
public:
    int ans = 0;

    void solve(int pos, int n, vector<bool>& used) {

        // All positions filled
        if (pos > n) {
            ans++;
            return;
        }

        for (int num = 1; num <= n; num++) {

            // Number already used
            if (used[num]) {
                continue;
            }

            // Check beautiful condition
            if (num % pos == 0 || pos % num == 0) {

                used[num] = true;

                solve(pos + 1, n, used);

                // Backtracking
                used[num] = false;
            }
        }
    }

    int countArrangement(int n) {

        vector<bool> used(n + 1, false);

        solve(1, n, used);

        return ans;
    }
};