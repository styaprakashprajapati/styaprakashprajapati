class Solution {
public:

    bool canEat(vector<int>& piles, int h, int k) {

        long long hours = 0;

        for (int pile : piles) {
            hours += (pile + k - 1) / k;

            if (hours > h)
                return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int st = 1;
        int end = *max_element(piles.begin(), piles.end());

        int ans = end;

        while (st <= end) {

            int mid = st + (end - st) / 2;

            if (canEat(piles, h, mid)) {

                // This speed works
                ans = mid;

                // Try smaller speed
                end = mid - 1;
            }
            else {

                // Speed is too slow
                st = mid + 1;
            }
        }

        return ans;
    }
};