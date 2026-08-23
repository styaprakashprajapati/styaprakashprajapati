class Solution {
public:
    int divide(int dividend, int divisor) {

        // Special overflow case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Convert to long long
        long long a = dividend;
        long long b = divisor;

        // Determine sign
        bool negative = (a < 0) ^ (b < 0);

        // Work with positive values
        a = llabs(a);
        b = llabs(b);

        long long ans = 0;

        while (a >= b) {

            long long current = b;
            long long count = 1;

            // Double divisor
            while (current <= a - current) {
                current += current;
                count += count;
            }

            // Subtract the biggest possible chunk
            a -= current;
            ans += count;
        }

        if (negative) {
            ans = -ans;
        }

        return (int)ans;
    }
};