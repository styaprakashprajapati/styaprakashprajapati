class Solution {
public:

    void solve(int n, int open, int close,
               string current,
               vector<string>& ans) {

        // n pairs complete
        if (current.size() == 2 * n) {
            ans.push_back(current);
            return;
        }

        // Opening bracket add kar sakte hain
        if (open < n) {
            solve(n, open + 1, close,
                  current + "(", ans);
        }

        // Closing bracket tabhi add karenge
        // jab opening brackets zyada hon
        if (close < open) {
            solve(n, open, close + 1,
                  current + ")", ans);
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;

        solve(n, 0, 0, "", ans);

        return ans;
    }
};