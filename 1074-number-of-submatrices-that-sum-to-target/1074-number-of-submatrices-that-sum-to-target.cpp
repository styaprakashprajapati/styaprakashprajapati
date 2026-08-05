class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int ans = 0;

        for (int left = 0; left < cols; left++) {

            vector<int> temp(rows, 0);

            for (int right = left; right < cols; right++) {

                // Add current column
                for (int r = 0; r < rows; r++) {
                    temp[r] += matrix[r][right];
                }

                unordered_map<int, int> mp;
                mp[0] = 1;

                int prefix = 0;

                for (int x : temp) {

                    prefix += x;

                    if (mp.count(prefix - target))
                        ans += mp[prefix - target];

                    mp[prefix]++;
                }
            }
        }

        return ans;
    }
};