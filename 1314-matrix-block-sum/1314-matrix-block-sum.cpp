class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {

        int rows = mat.size();
        int cols = mat[0].size();

        vector<vector<int>> prefix(rows + 1,
                                   vector<int>(cols + 1, 0));

        // Build Prefix Sum
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {

                prefix[i][j] =
                    mat[i - 1][j - 1]
                    + prefix[i - 1][j]
                    + prefix[i][j - 1]
                    - prefix[i - 1][j - 1];
            }
        }

        vector<vector<int>> ans(rows, vector<int>(cols));

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {

                int r1 = max(0, i - k);
                int c1 = max(0, j - k);

                int r2 = min(rows - 1, i + k);
                int c2 = min(cols - 1, j + k);

                ans[i][j] =
                    prefix[r2 + 1][c2 + 1]
                    - prefix[r1][c2 + 1]
                    - prefix[r2 + 1][c1]
                    + prefix[r1][c1];
            }
        }

        return ans;
    }
};