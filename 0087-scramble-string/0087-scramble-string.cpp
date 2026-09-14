class Solution {
public:

    unordered_map<string, bool> memo;

    bool solve(string s1, string s2) {

        // Same string hai
        if (s1 == s2) {
            return true;
        }

        // Different characters/frequency hain
        string temp1 = s1;
        string temp2 = s2;

        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());

        if (temp1 != temp2) {
            return false;
        }

        // Memoization
        string key = s1 + "#" + s2;

        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        int n = s1.size();

        // Har possible split try karo
        for (int k = 1; k < n; k++) {

            // Case 1: No swap
            bool noSwap =
                solve(s1.substr(0, k),
                      s2.substr(0, k))
                &&
                solve(s1.substr(k),
                      s2.substr(k));

            if (noSwap) {
                return memo[key] = true;
            }

            // Case 2: Swap
            bool swap =
                solve(s1.substr(0, k),
                      s2.substr(n - k))
                &&
                solve(s1.substr(k),
                      s2.substr(0, n - k));

            if (swap) {
                return memo[key] = true;
            }
        }

        return memo[key] = false;
    }

    bool isScramble(string s1, string s2) {

        if (s1.size() != s2.size()) {
            return false;
        }

        return solve(s1, s2);
    }
};