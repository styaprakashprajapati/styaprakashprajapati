class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {

        vector<vector<int>> ans;

        ans.push_back({rStart, cStart});

        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {1, 0, -1, 0};

        int dir = 0;
        int steps = 1;

        while (ans.size() < rows * cols) {

            // Right and Down
            for (int k = 0; k < 2; k++) {
                for (int i = 0; i < steps; i++) {

                    rStart += dr[dir];
                    cStart += dc[dir];

                    if (rStart >= 0 && rStart < rows &&
                        cStart >= 0 && cStart < cols) {
                        ans.push_back({rStart, cStart});
                    }
                }
                dir = (dir + 1) % 4;
            }

            steps++;

            // Left and Up
            for (int k = 0; k < 2; k++) {
                for (int i = 0; i < steps; i++) {

                    rStart += dr[dir];
                    cStart += dc[dir];

                    if (rStart >= 0 && rStart < rows &&
                        cStart >= 0 && cStart < cols) {
                        ans.push_back({rStart, cStart});
                    }
                }
                dir = (dir + 1) % 4;
            }

            steps++;
        }

        return ans;
    }
};