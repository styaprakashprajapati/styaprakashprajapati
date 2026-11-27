class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

        // {x, height, right}
        vector<tuple<int, int, int>> events;

        for (auto &b : buildings) {
            events.push_back({b[0], -b[2], b[1]});
            events.push_back({b[1], 0, 0});
        }

        sort(events.begin(), events.end());

        // {height, right}
        priority_queue<pair<int, int>> pq;

        pq.push({0, INT_MAX});

        vector<vector<int>> ans;

        for (auto &[x, h, right] : events) {

            // Add a new building
            if (h < 0) {
                pq.push({-h, right});
            }

            // Remove buildings that have ended
            while (!pq.empty() && pq.top().second <= x) {
                pq.pop();
            }

            int maxHeight = pq.top().first;

            // Skyline changes
            if (ans.empty() || ans.back()[1] != maxHeight) {
                ans.push_back({x, maxHeight});
            }
        }

        return ans;
    }
};