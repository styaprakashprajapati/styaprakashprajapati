class Solution {
public:

    long long dist(vector<int>& a, vector<int>& b) {
        long long dx = a[0] - b[0];
        long long dy = a[1] - b[1];

        return dx * dx + dy * dy;
    }

    bool validSquare(vector<int>& p1,
                     vector<int>& p2,
                     vector<int>& p3,
                     vector<int>& p4) {

        vector<long long> d;

        d.push_back(dist(p1, p2));
        d.push_back(dist(p1, p3));
        d.push_back(dist(p1, p4));
        d.push_back(dist(p2, p3));
        d.push_back(dist(p2, p4));
        d.push_back(dist(p3, p4));

        sort(d.begin(), d.end());

        // 4 equal sides
        // 2 equal diagonals
        // side length must be smaller than diagonal
        return d[0] > 0 &&
               d[0] == d[1] &&
               d[1] == d[2] &&
               d[2] == d[3] &&
               d[4] == d[5] &&
               d[3] < d[4];
    }
};