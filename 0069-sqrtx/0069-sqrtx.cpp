class Solution {
public:
    int mySqrt(int x) {

        if (x < 2)
            return x;

        long long st = 1;
        long long end = x;
        long long ans = 0;

        while (st <= end) {

            long long mid = st + (end - st) / 2;

            if (mid <= x / mid) {
                // mid ka square x se chhota/equal hai
                ans = mid;

                // Aur bada answer try karo
                st = mid + 1;
            }
            else {
                // mid bahut bada hai
                end = mid - 1;
            }
        }

        return ans;
    }
};