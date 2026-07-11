class Solution {
    static constexpr int MOD = 1'000'000'007;

    struct Event {
        int x, y1, y2, type;
        bool operator<(const Event& other) const {
            return x < other.x;
        }
    };

    vector<int> count;
    vector<long long> length;
    vector<int> ys;

    void update(int node, int l, int r, int ql, int qr, int val) {
        if (qr <= l || r <= ql) return;

        if (ql <= l && r <= qr) {
            count[node] += val;
        } else {
            int mid = (l + r) / 2;
            update(node * 2, l, mid, ql, qr, val);
            update(node * 2 + 1, mid, r, ql, qr, val);
        }

        if (count[node] > 0) {
            length[node] = ys[r] - ys[l];
        } else if (r - l == 1) {
            length[node] = 0;
        } else {
            length[node] = length[node * 2] + length[node * 2 + 1];
        }
    }

public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        vector<Event> events;

        for (auto &rec : rectangles) {
            events.push_back({rec[0], rec[1], rec[3], 1});
            events.push_back({rec[2], rec[1], rec[3], -1});
            ys.push_back(rec[1]);
            ys.push_back(rec[3]);
        }

        sort(events.begin(), events.end());

        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());

        count.assign(ys.size() * 4, 0);
        length.assign(ys.size() * 4, 0);

        long long area = 0;
        int prevX = events[0].x;

        for (auto &e : events) {
            area = (area + length[1] * (e.x - prevX)) % MOD;

            int y1 = lower_bound(ys.begin(), ys.end(), e.y1) - ys.begin();
            int y2 = lower_bound(ys.begin(), ys.end(), e.y2) - ys.begin();

            update(1, 0, ys.size() - 1, y1, y2, e.type);

            prevX = e.x;
        }

        return (int)area;
    }
};