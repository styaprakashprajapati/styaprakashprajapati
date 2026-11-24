class Solution {
public:

    bool dfs(string &num, int index,
             long long first, long long second) {

        // All digits used successfully
        if (index == num.size()) {
            return true;
        }

        string sum = to_string(first + second);

        // Check whether next part matches sum
        if (num.substr(index, sum.size()) != sum) {
            return false;
        }

        return dfs(num, index + sum.size(),
                   second, first + second);
    }

    bool isAdditiveNumber(string num) {

        int n = num.size();

        for (int i = 1; i <= n / 2; i++) {

            // Leading zero not allowed
            if (num[0] == '0' && i > 1) {
                break;
            }

            long long first = stoll(num.substr(0, i));

            for (int j = i + 1; j < n; j++) {

                int len = j - i;

                // Leading zero not allowed
                if (num[i] == '0' && len > 1) {
                    break;
                }

                // At least one digit must remain
                // for the third number
                if (n - j < max(i, len)) {
                    break;
                }

                long long second =
                    stoll(num.substr(i, len));

                if (dfs(num, j, first, second)) {
                    return true;
                }
            }
        }

        return false;
    }
};