class Solution {
public:

    unordered_map<int, bool> memo;

    bool solve(int used, int remaining, int maxNum) {

        if (memo.count(used))
            return memo[used];

        for (int num = 1; num <= maxNum; num++) {

            int bit = 1 << (num - 1);

            // Already used
            if (used & bit)
                continue;

            // Current player wins immediately
            if (num >= remaining)
                return memo[used] = true;

            // Choose num
            int newUsed = used | bit;

            // Opponent loses => current player wins
            if (!solve(newUsed,
                       remaining - num,
                       maxNum)) {

                return memo[used] = true;
            }
        }

        return memo[used] = false;
    }

    bool canIWin(int maxChoosableInteger,
                 int desiredTotal) {

        int maxSum = maxChoosableInteger *
                     (maxChoosableInteger + 1) / 2;

        // Even all numbers are not enough
        if (maxSum < desiredTotal)
            return false;

        if (desiredTotal <= 0)
            return true;

        return solve(0, desiredTotal,
                     maxChoosableInteger);
    }
};