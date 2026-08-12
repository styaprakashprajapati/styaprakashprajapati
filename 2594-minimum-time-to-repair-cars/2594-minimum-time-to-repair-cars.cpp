class Solution {
public:

    bool canRepair(vector<int>& ranks, int cars, long long time) {

        long long repaired = 0;

        for (int rank : ranks) {

            // Number of cars this mechanic can repair
            long long canDo = sqrt(time / rank);

            repaired += canDo;

            // We already have enough mechanics
            if (repaired >= cars) {
                return true;
            }
        }

        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {

        int minRank = *min_element(ranks.begin(), ranks.end());

        long long st = 1;

        long long end = 1LL * minRank * cars * cars;

        long long ans = end;

        while (st <= end) {

            long long mid = st + (end - st) / 2;

            if (canRepair(ranks, cars, mid)) {

                // This time is possible
                ans = mid;

                // Try even smaller time
                end = mid - 1;
            }
            else {

                // Not enough time
                st = mid + 1;
            }
        }

        return ans;
    }
};