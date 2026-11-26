class Solution {
public:
    int hIndex(vector<int>& citations) {

        int n = citations.size();

        vector<int> count(n + 1, 0);

        // Count citations
        for (int c : citations) {

            if (c >= n) {
                count[n]++;
            }
            else {
                count[c]++;
            }
        }

        int papers = 0;

        // Check from highest citation count
        for (int h = n; h >= 0; h--) {

            papers += count[h];

            if (papers >= h) {
                return h;
            }
        }

        return 0;
    }
};