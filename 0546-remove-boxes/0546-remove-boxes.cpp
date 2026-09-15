class Solution {
public:
    int dp[100][100][100];

    int solve(vector<int>& boxes, int l, int r, int k) {
        if (l > r) {
            return 0;
        }

        if (dp[l][r][k] != -1) {
            return dp[l][r][k];
        }

        // Consecutive same boxes ko k mein merge karo
        int originalL = l;

        while (l + 1 <= r && boxes[l] == boxes[l + 1]) {
            l++;
            k++;
        }

        // Option 1: current group ko remove karo
        int ans = (k + 1) * (k + 1)
                + solve(boxes, l + 1, r, 0);

        // Option 2: future same color ke saath merge karo
        for (int m = l + 1; m <= r; m++) {

            if (boxes[m] == boxes[l]) {

                int left = solve(boxes, l + 1, m - 1, 0);

                int right = solve(boxes, m, r, k + 1);

                ans = max(ans, left + right);
            }
        }

        return dp[originalL][r][k - (l - originalL)] = ans;
    }

    int removeBoxes(vector<int>& boxes) {
        memset(dp, -1, sizeof(dp));

        return solve(boxes, 0, boxes.size() - 1, 0);
    }
};