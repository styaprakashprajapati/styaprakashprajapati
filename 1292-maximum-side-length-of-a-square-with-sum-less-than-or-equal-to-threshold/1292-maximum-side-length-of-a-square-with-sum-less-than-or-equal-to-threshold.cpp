class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {

        int rows = mat.size();
        int cols = mat[0].size();

        vector<vector<int>> prefix(rows + 1,
                                   vector<int>(cols + 1, 0));

        // Build prefix sum
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {

                prefix[i][j] =
                    mat[i - 1][j - 1]
                    + prefix[i - 1][j]
                    + prefix[i][j - 1]
                    - prefix[i - 1][j - 1];
            }
        }

        int ans = 0;

        for (int len = 1; len <= min(rows, cols); len++) {

            for (int i = 0; i + len <= rows; i++) {

                for (int j = 0; j + len <= cols; j++) {

                    int sum =
                        prefix[i + len][j + len]
                        - prefix[i][j + len]
                        - prefix[i + len][j]
                        + prefix[i][j];

                    if (sum <= threshold)
                        ans = len;
                }
            }
        }

        return ans;
    }
};