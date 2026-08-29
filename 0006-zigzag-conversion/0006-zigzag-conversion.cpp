class Solution {
public:
    string convert(string s, int numRows) {

        // Agar sirf 1 row hai,
        // to zigzag ki zarurat nahi
        if (numRows == 1 || numRows >= s.size()) {
            return s;
        }

        vector<string> rows(numRows);

        int row = 0;
        int direction = 1;   // 1 = down, -1 = up

        for (char ch : s) {

            // Character ko current row mein rakho
            rows[row] += ch;

            // Last row par pahunch gaye
            if (row == numRows - 1) {
                direction = -1;
            }

            // First row par pahunch gaye
            else if (row == 0) {
                direction = 1;
            }

            // Next row
            row += direction;
        }

        // Saari rows ko join karo
        string ans;

        for (string &r : rows) {
            ans += r;
        }

        return ans;
    }
};