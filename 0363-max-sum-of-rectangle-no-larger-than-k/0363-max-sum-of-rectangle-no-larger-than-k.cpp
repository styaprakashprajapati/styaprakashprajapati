class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int ans = INT_MIN;

        for (int left = 0; left < cols; left++) {

            vector<int> temp(rows, 0);

            for (int right = left; right < cols; right++) {

                for (int r = 0; r < rows; r++)
                    temp[r] += matrix[r][right];

                set<int> prefix;
                prefix.insert(0);

                int curr = 0;

                for (int x : temp) {

                    curr += x;

                    auto it = prefix.lower_bound(curr - k);

                    if (it != prefix.end()) {
                        ans = max(ans, curr - *it);
                    }

                    prefix.insert(curr);
                }
            }
        }

        return ans;
    }
};